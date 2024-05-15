#include <Arduino.h>

#include <lvgl.h>

#include "ui.h"
#include "ui_helpers.h"

// wifi configuration portal
#include <IotWebConf.h>
#include <WiFi.h>

// configure uploading via wifi from PlatformIO
#include <ArduinoOTA.h>

// firmware.bin upload via web browser
#include <ElegantOTA.h>

#include <uri/UriBraces.h>

#include "CST820.h"
#define LGFX_USE_V1      // set to use new version of library
#include <LovyanGFX.hpp>

#include "typedefs.hpp"
#include <LittleFS.h>
#include "ed_flag_helpers.hpp"

#define switchToScreen(x) lv_scr_load_anim(x, LV_SCR_LOAD_ANIM_OVER_RIGHT, 2000, 50, false)

#define TFT_WIDTH 240
#define TFT_HEIGHT 320

#define I2C_SDA 21
#define I2C_SCL 22

CST820 touch(I2C_SDA, I2C_SCL, -1, -1); /* 触摸实例 */
//CST820 touch(-1, -1, -1, -1);

static lv_disp_draw_buf_t draw_buf;
// static lv_color_t buf[TFT_WIDTH * 100];
lv_indev_t *myInputDevice;

class LGFX : public lgfx::LGFX_Device
{

    lgfx::Panel_ST7789 _panel_instance; // ST7789UI
    lgfx::Bus_Parallel8 _bus_instance;  // MCU8080 8B


public:
    LGFX(void)
    {
        {
            auto cfg = _bus_instance.config();
            cfg.freq_write = 25000000;
            cfg.pin_wr = 4;
            cfg.pin_rd = 2;
            cfg.pin_rs = 16;

            cfg.pin_d0 = 15;
            cfg.pin_d1 = 13;
            cfg.pin_d2 = 12;
            cfg.pin_d3 = 14;
            cfg.pin_d4 = 27;
            cfg.pin_d5 = 25;
            cfg.pin_d6 = 33;
            cfg.pin_d7 = 32;

            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }

        {
            auto cfg = _panel_instance.config();

            cfg.pin_cs = 17;
            cfg.pin_rst = -1;
            cfg.pin_busy = -1;

            cfg.panel_width = 240;
            cfg.panel_height = 320;
            cfg.offset_x = 0;
            cfg.offset_y = 0;
            cfg.offset_rotation = 0;
            // cfg.dummy_read_pixel = 8;
            // cfg.dummy_read_bits = 1;
            cfg.readable = false;
            cfg.invert = false;
            cfg.rgb_order = false;
            cfg.dlen_16bit = false;
            cfg.bus_shared = true;

            _panel_instance.config(cfg);
        }

        setPanel(&_panel_instance);
    }
};

static LGFX display;

// SSID & Password for inital wifi config
const char thingName[] = "ED Fuel Gauge";
const char wifiInitialApPassword[] = "showmelevels";


flags_t flag_info = { 0,0,0 };

fueldata_t fuel_info = {6, 32.0, 0.25, 0.25, true, 0 ,0, 0, cmdWiFiConfig};


// Task handles, functions and info queue
TaskHandle_t  tskOTA, tskBlink, tskDisplay;
QueueHandle_t QueueHandle, quFlags, mutex;
#define LOCK xSemaphoreTake(mutex, portMAX_DELAY)
#define RELEASE xSemaphoreGive(mutex)

void doOTA(void *parameter);
void updateDisplay(void *parameter);
void ledFlagBlink(void * parameter);

// web request handler
void handleRoot();

// default Page Html send
void sendHTML();

DNSServer dnsServer;
WebServer server(80);
IotWebConf iotWebConf(thingName, &dnsServer, &server, wifiInitialApPassword);

/*
    lcd interface
    transfer pixel data range to lcd
*/
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int w = (area->x2 - area->x1 + 1);
    int h = (area->y2 - area->y1 + 1);

    display.startWrite();                            /* Start new TFT transaction */
    display.setAddrWindow(area->x1, area->y1, w, h); /* set the working window */
    display.writePixels(&color_p->full, w * h,false);//true

    display.endWrite();            /* terminate TFT transaction */
    lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

    bool touched;
    uint8_t gesture;
    uint16_t touchX, touchY;

    touched = touch.getTouch(&touchX, &touchY, &gesture);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
}


void setup() {
// the only pins available (0 and 2), are shared
// with the bootloader, so always set them HIGH at power-up
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  
  mutex = xSemaphoreCreateMutex();
  unsigned long cmills;
  unsigned long pmills;

  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  while(!Serial) delay(10);

  lv_init();
  
  display.init();

  touch.begin();

  display.fillScreen(TFT_BLACK);

  lv_color_t *buf1 = (lv_color_t *)heap_caps_malloc(TFT_HEIGHT * 150 * sizeof(lv_color_t), MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
  lv_color_t *buf2 = (lv_color_t *)heap_caps_malloc(TFT_HEIGHT * 150 * sizeof(lv_color_t), MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);

  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, TFT_HEIGHT * 150);

  // initialise the display
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  // settings for display driver
  disp_drv.hor_res = TFT_WIDTH;
  disp_drv.ver_res = TFT_HEIGHT;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  //disp_drv.rotated = LV_DISP_ROT_90;
  lv_disp_drv_register(&disp_drv);
  

  // initialise touch
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  display.setTextSize((std::max(display.width(), display.height()) + 255) >> 8);
  

  display.fillScreen(TFT_BLACK);
  ui_init();

  String passset = String(lv_label_get_text(ui_lblWifiInfo));
  passset.replace("*PASS*", wifiInitialApPassword);
  lv_label_set_text(ui_lblWifiInfo, passset.c_str());
  Serial.print("ss");
  lv_disp_load_scr(ui_screenWiFiConfig);
  lv_obj_add_flag(ui_lblWifiInfo, LV_OBJ_FLAG_HIDDEN);
  lv_timer_handler();
  Serial.print("se");
    // queues for passing info between tasks
  QueueHandle = xQueueCreate(10, sizeof(fueldata_t));
  quFlags = xQueueCreate(10, sizeof(flags_t));

  // Check if the queue was successfully created
  if (QueueHandle == NULL || quFlags == NULL) {
    Serial.println("Queue could not be created. Halt.");
    while (1) {
      delay(1000);  // Halt at this point as is not possible to continue
    }
  }
  
  if (!LittleFS.begin(false, "/littlefs")) {
    Serial.print("Error opening storage filesystem");
  }
  if (LittleFS.exists("/img/elite-dangerous-logo.png")) {
    Serial.println("Logo found");
  } else {
    Serial.println("Logo NOT found");
  }

  // -- Initializing wifi configuration.
  iotWebConf.init();
  iotWebConf.setApTimeoutMs(200);

  // -- Set up required URL handlers on the web server.
  server.on("/", handleRoot);
  server.on("/config", []{ iotWebConf.handleConfig(); });

  // treat unknown pages as asking for /
  server.onNotFound([](){ handleRoot(); });
  // img files
  server.serveStatic("/img", LittleFS, "/img/");

  // fuel level update
  server.on(UriBraces("/fuel/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.fuellevel = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    Serial.printf("New Fuel Level = %0.2f\r\n", fuel_info.fuellevel);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // fuel tank size update
  server.on(UriBraces("/fueltank/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.fuelcap = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    Serial.printf("New Fuel Capacity = %0.2f\r\n", fuel_info.fuelcap);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // resrv level update
  server.on(UriBraces("/res/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.reslevel = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    Serial.printf("New res Level = %0.2f\r\n", fuel_info.fuellevel);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // resrv capacity
  server.on(UriBraces("/restank/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.rescap = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    Serial.printf("New res cap = %0.2f\r\n", fuel_info.fuellevel);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // backlight request
  server.on(UriBraces("/light/{}"), []() {
    String value = server.pathArg(0);
    value.toLowerCase();
    fuel_info.light = (value == "on"?true:false);
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });  

  // level & light update in one get request
  server.on("/data", []() {
    fuel_info.fuellevel = server.arg("fuel").toFloat();
    fuel_info.reslevel = server.arg("res").toFloat();
    fuel_info.fuelcap = server.arg("fueltank").toFloat();
    fuel_info.rescap = server.arg("restank").toFloat();
    String value =  server.arg("light");
    Serial.printf("args\r\nfuel: %s\r\nres: %s\r\nfueltank: %s\r\nrestank: %s\r\n------\r\n", 
        server.arg("fuel"), 
        server.arg("res"), 
        server.arg("fueltank"),
        server.arg("restank"));
    value.toLowerCase();
    fuel_info.light = (value=="on"?true:false);
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // flags
  server.on("/flags", []() {
    flag_info.flags = server.arg("flags").toInt();
    flag_info.flags2 = server.arg("flags2").toInt();
    flag_info.cmdtime = millis();
    memcpy(&fuel_info.flags, &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    xQueueSend(quFlags, &flag_info, portMAX_DELAY);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
});
  // ship name at top of screen
  server.on("/name", []() {
    String shipname = server.arg("name");
    LOCK;
    lv_label_set_text(ui_lblShipName, shipname.c_str());
    RELEASE;
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });
      
  // reboot witho confirmation
  server.on("/reboot", [](){
    server.send(200, "text/html",
      "<!DOCTYPE html><html><head></head><body><p>Rebooting</p></body></html>"
    );
    delay(500);
    server.stop();
    server.close();
    ESP.restart();
  });

  server.on("/endsession",[]() {
    fuel_info.cmd = cmdWaitingForStartup;
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });
  // platformio OTA enable
  server.on("/OTA",[]() {
    server.send(200,"text/html",
      R"(<!DOCTYPE html><html>
        <head><title>ED Fuel Gauge OTA</title></head>
        <body><h1>OTA ACTIVE</h1><p>power off and on to abort<p></body></html>)"
    );
    server.stop();
    server.close();
    // start OTA task as high priority then kill this task
    Serial.println("----\r\nOTA NOW ACTIVE\r\n----");
    xTaskCreatePinnedToCore(
      doOTA,
      "OTA On",
      10000,
      NULL,
      2,
      &tskOTA,
      xPortGetCoreID()
    );
    vTaskDelete(NULL);
  });
  // -- End of URL handlers

  // wait for connection to WiFi
  cmills = millis();
  pmills = cmills;
  while (iotWebConf.getState() != iotwebconf::OnLine) {
    if (cmills - pmills > 1500) {
      lv_obj_clear_flag(ui_lblWifiInfo, LV_OBJ_FLAG_HIDDEN);
    }
    iotWebConf.doLoop();
    lv_timer_handler();
    cmills = millis();
  }

  String myIpAddress = WiFi.localIP().toString();
  passset = String(lv_label_get_text(ui_lblWaiting));
  passset.replace("*IP*", myIpAddress);
  lv_label_set_text(ui_lblWaiting, passset.c_str());
  //lv_disp_load_scr(ui_screenWaitingForData);
  //lv_scr_load_anim(ui_screenWaitingForData, LV_SCR_LOAD_ANIM_OVER_RIGHT, 2000, 50, false);
  switchToScreen(ui_screenWaitingForData);
  lv_timer_handler();
  fuel_info.cmd = cmdFuel;

  memset(&flag_info, 0, sizeof(flags_t));
  xQueueSend(quFlags, &flag_info, 1);

  ElegantOTA.begin(&server);    // Start ElegantOTA
  xTaskCreatePinnedToCore( ledFlagBlink, "blink", 3000, NULL, 1, &tskBlink, xPortGetCoreID() );
  xTaskCreatePinnedToCore( updateDisplay, "display", 3000, NULL, 1, &tskDisplay, xPortGetCoreID() );
  Serial.println("Ready.");
}


void loop() {
    iotWebConf.doLoop();
    ElegantOTA.loop();
    //updateDisplay(NULL);
    //ledFlagBlink(NULL);
    LOCK;
    lv_timer_handler();
    RELEASE;
}

void doOTA(void *parameter){
ArduinoOTA.setHostname("EDFuelGauge-OTA");
    ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        type = "sketch";
      } else {  // U_SPIFFS
        type = "filesystem";
      }

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) {
        Serial.println("Auth Failed");
      } else if (error == OTA_BEGIN_ERROR) {
        Serial.println("Begin Failed");
      } else if (error == OTA_CONNECT_ERROR) {
        Serial.println("Connect Failed");
      } else if (error == OTA_RECEIVE_ERROR) {
        Serial.println("Receive Failed");
      } else if (error == OTA_END_ERROR) {
        Serial.println("End Failed");
      }
    });
    ArduinoOTA.begin();
    
    while(1) ArduinoOTA.handle();
}

void updateDisplay(void *parameter){
  float f, fc, r, rc;
  fueldata_t fuelinfo;
  String fuelInfo;
  uint8_t percentage;
  lv_obj_t * activescreen;
  
  for(;;){
    // obtain current stats
    xQueueReceive(QueueHandle, &fuelinfo, portMAX_DELAY);

    // if on foot don't update
    if (fuelinfo.flags.flags2 & edflags2::OnFoot) {
      continue;
    }

    LOCK;
    activescreen = lv_disp_get_scr_act(NULL);
    RELEASE;

    // if in srv set Main Tank = Res & Res = 0
    if (fuelinfo.flags.flags & edflags::InSRV) {
      //fuelinfo.fuellevel = fuelinfo.reslevel;
      fuelinfo.reslevel = 0;
      fuelinfo.fuelcap = 0.5;
    }
    switch(fuelinfo.cmd) {
      case cmdFuel:
        f = fuelinfo.fuellevel;
        fc = fuelinfo.fuelcap;
        r = fuelinfo.reslevel;
        rc = fuelinfo.rescap;
        LOCK;
        if (!fuelinfo.light) {
          lv_obj_clear_flag(ui_cntDimmer, LV_OBJ_FLAG_HIDDEN);
        } else {
          lv_obj_add_flag(ui_cntDimmer, LV_OBJ_FLAG_HIDDEN);
        }
        RELEASE;
        // basic sanity checks -- should really add a lot more
        // if level > cap - set cap to level
        if (f > fc) fc = f;
        if (r > rc) rc = r;

        LOCK;
        // draw main tank bars
        percentage = (uint8_t)((f/fc)*100);
        lv_bar_set_value(ui_brMain, percentage, LV_ANIM_ON);

        // draw reservoir bar
        percentage = (uint8_t)((r/rc)*100);
        lv_bar_set_value(ui_brRes, percentage, LV_ANIM_ON);

        // string values
        fuelInfo = String(f,2)+"t";
        lv_label_set_text(ui_lblMainFuel, fuelInfo.c_str());
        fuelInfo = String(r,3)+"t";
        lv_label_set_text(ui_lblResFuel, fuelInfo.c_str());
        if (activescreen != ui_ScreenFuel) {
          //lv_disp_load_scr(ui_ScreenFuel);
          switchToScreen(ui_ScreenFuel);
        }
        RELEASE;
        break;
      case cmdWiFiConfig:
        //lv_disp_load_scr(ui_screenWiFiConfig);
        LOCK;
        switchToScreen(ui_screenWiFiConfig);
        RELEASE;
        break;    
      case cmdWaitingForStartup:
        //lv_disp_load_scr(ui_screenWaitingForData);
        LOCK;
        switchToScreen(ui_screenWaitingForData);
        RELEASE;
        break;
    }
  }
}

void ledFlagBlink(void *parameter){
  unsigned long currentMs = millis();
  static unsigned long msCharge = 0, msCooldown = 0, msLowFuel = 0, msJumping = 0;
  static bool bgIsRed = false, blinking=false, spinVisible = false;
  bool fsdActivity = false;
  static uint16_t fsdchargetime;

  flags_t flags;
  static flags_t prevflags = {0,0};
  for(;;){
    if (!xQueueReceive(quFlags, &flags, 0)) {
      if (!blinking){
        //memcpy(&prevflags, &flags, sizeof(flags_t));
        continue;
      } else {
        //Serial.println("No queue item but blinking");
      }
      memcpy(&flags, &prevflags, sizeof(flags_t));
    } else {

      //Serial.printf("Flags: %d\r\n", flags.flags & edflags::FsdCooldown);
    }
    currentMs = millis();
    blinking = false;
    fsdActivity = false;
  //  lv_obj_add_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);

    // low fuel flasher
    if (flags.flags & edflags::LowFuel) {
      LOCK;
      lv_obj_clear_flag(ui_spinLowFuel, LV_OBJ_FLAG_HIDDEN);
      RELEASE;
      blinking = true;
      if (currentMs - msLowFuel > 500) {
        
        bgIsRed = !bgIsRed;
        // cycle colour
        LOCK;
        if (bgIsRed) {
          lv_obj_set_style_bg_color(ui_ScreenFuel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else {
          lv_obj_set_style_bg_color(ui_ScreenFuel, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        RELEASE;
        msLowFuel = currentMs;
      }
    } else {
      bgIsRed = false;
      LOCK;
      lv_obj_set_style_bg_color(ui_ScreenFuel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_add_flag(ui_spinLowFuel, LV_OBJ_FLAG_HIDDEN);
      RELEASE;
    }

    //charging
    if ((flags.flags & edflags::FsdCharging) && !(flags.flags & edflags::FsdJump)) {
      blinking = true;
      fsdActivity = true;
      if (!(prevflags.flags & edflags::FsdCharging)) {
        fsdchargetime = (flags.flags2 & edflags2::HyperdriveCharging)?10000:4000;
        Serial.printf("Started CHarging %d (flags:%d)\r\n", fsdchargetime, flags.flags2);
        LOCK;
        lv_arc_set_value(ui_spinCharging, 0);
        lv_obj_clear_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
        RELEASE;
        //msCharge = flags.cmdtime;
        msCharge = currentMs;
      }
      uint16_t currentPercent = (uint16_t)(((currentMs - msCharge)*100/fsdchargetime));
      if (currentPercent > 100) {
        currentPercent = 0;
        msCharge = currentMs;
      }
      //Serial.printf("cm: %d - ms:%d  = %% %d\r\n", currentMs, msCharge, currentPercent);
      LOCK;
      lv_arc_set_value(ui_spinCharging, currentPercent);
      RELEASE;
    } 

    // cooldown
    if (flags.flags & edflags::FsdCooldown) {
      int16_t currentPercent;// = lv_arc_get_value(ui_spinCharging);
      blinking = true;
      fsdActivity = true;
      if (!(prevflags.flags & edflags::FsdCooldown)) {
        Serial.println("cooldown");      
        LOCK;
        lv_arc_set_value(ui_spinCharging, 100);
        RELEASE;
        currentPercent = 100;
        msCooldown = flags.cmdtime;
      }
      currentPercent = 100-(uint16_t)(((currentMs-msCooldown)*100)/10000);  // should be 10s
      if (currentPercent < 0) {
        currentPercent = 100;
        msCooldown = currentMs;
      }
      LOCK;
      lv_arc_set_value(ui_spinCharging, currentPercent);
      lv_obj_clear_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
      RELEASE;

    }
    
    if (flags.flags & edflags::FsdJump) {
      if (!(prevflags.flags & edflags::FsdJump)) {
        LOCK;
        lv_arc_set_value(ui_spinCharging, 100);
        RELEASE;
      }
      blinking = true;
      if (currentMs - msJumping > 500) {
        spinVisible = !spinVisible;
        LOCK;
        if (spinVisible) {
          lv_obj_add_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
        } else {
          lv_obj_clear_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
        }
        RELEASE;
        msJumping = currentMs;
      }
    }

    if ( !(flags.flags & edflags::FsdJump)) {
      LOCK;
      if (fsdActivity) {
        lv_obj_clear_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
      } else {
        lv_obj_add_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
      }
       RELEASE;

    }
    memcpy(&prevflags, &flags, sizeof(flags_t));
    flags_t  peekedflags;
    if (xQueuePeek(quFlags, &peekedflags, 0)) {
      if (!memcmp(&prevflags, &peekedflags, sizeof(flags_t))) {
        xQueueReceive(quFlags, &peekedflags, 0);
      } 
    }
  }
}

/**
 * Handle web requests to "/" path.
 */
void handleRoot()
{
  // -- Let IotWebConf test and handle captive portal requests.
  if (iotWebConf.handleCaptivePortal())
  {
    // -- Captive portal request were already served.
    return;
  }
  sendHTML();
}


void sendHTML() {
  // send HTML page to client
  String response = R"(
    <!DOCTYPE html>
      <html>
        <head>
          <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">
          <link rel=\"icon\" href=\"data:,\">
          <title>ED Fuel Gauge</title>
        </head>
        <body><img src="/img/elite-dangerous-logo.png" style="float:left" />
          <h1>ED Fuel Display</h1>
          <p>Current Fuel FUELLEVEL</p>
          <p>Fuel Tank FUELTANK</p>
          <p>Resrv RESRV / RESTANK</p>
          <p><br /><br /><br /></p><p></p><h2>Pages</h2><p>
          <ul><li>/fuel/??.??  - set fuel level  </li>
          <li>/fueltank/??.??  - max fuel</li>
          <li>/res/??.??  - resrv level</li>
          <li>/restank/??.??   - resrv tank size</li>
          <li>/light/[<a href="/light/on">on</a> | <a href="/light/off">off</a>]  - screen dimmer of or on</p>
          <p>single url version<br/>/data?fuel=&lt;value&gt;&res=&lt;value&gt;&fueltank=&lt;value&gt;&restank=&lt;value&gt;&light=[on|off]</p>
          <p>Extra Info bits - status.json flag values<br/>/flags?flags=&lt;value&gt;&flags2=&lt;value&gt;<br/>
          <hr /><h2>Extra functions</h2>
          <ul><li>/reboot - <b>reboot without confirmation</b></li>
          <li><a href="/config">/config</a> - WiFi configuration</li>
          <li><a href="/OTA">/OTA</a> - enable OTA uploading from platformio</li>
          <li><a href="/update">/update</a> - Manual Firmware upload</li>
          </ul>
          
          </body></html>
  )";
  response.replace("FUELLEVEL", String(fuel_info.fuellevel,2));
  response.replace("FUELTANK", String(fuel_info.fuelcap,2));
  response.replace("RESRV", String(fuel_info.reslevel,3));
  response.replace("RESTANK", String(fuel_info.rescap, 2));
  server.send(200, "text/html", response);
}