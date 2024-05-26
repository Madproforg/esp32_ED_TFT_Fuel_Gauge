#include <Arduino.h>

#include <lvgl.h>

#include "ui.h"
#include "ui_helpers.h"

// wifi configuration portal
#include <IotWebConf.h>
#include <WiFi.h>

#include <uri/UriBraces.h>
#include <esp32_smartdisplay.h>

#include "typedefs.hpp"
#include <LittleFS.h>
#include <Preferences.h>
#include "ed_flag_helpers.hpp"

#define switchToScreen(x) lv_scr_load_anim(x, LV_SCR_LOAD_ANIM_OVER_RIGHT, 2000, 50, false)

#define TFT_WIDTH 240
#define TFT_HEIGHT 320



// SSID & Password for inital wifi config
const char thingName[] = "ED Fuel Gauge";
const char wifiInitialApPassword[] = "showmelevels";


flags_t flag_info = { 0,0,0 };

fueldata_t fuel_info = {6, 32.0, 0.25, 0.25, true, 0 ,0, 0, cmdWiFiConfig};


// Task handles, functions and info queue
TaskHandle_t  tskBlink, tskDisplay;
QueueHandle_t QueueHandle, quFlags, mutex;
#define LOCK xSemaphoreTake(mutex, portMAX_DELAY)
#define RELEASE xSemaphoreGive(mutex)

void updateDisplay(void *parameter);
void ledFlagBlink(void * parameter);

// web request handler
void handleRoot();

// default Page Html send
void sendHTML();

DNSServer dnsServer;
WebServer server(80);
IotWebConf iotWebConf(thingName, &dnsServer, &server, wifiInitialApPassword);

// Save values for hypercharge, sc charge and cooldown times
Preferences preferences;
unsigned long hyperchargetime;
unsigned long scchargetime;
unsigned long cooldowntime;
uint8_t brightnesson;
uint8_t brightnessoff;


void setup() {
// the only pins available (0), are shared
// with the bootloader, so always set them HIGH at power-up
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);

  // pin 0 is scren backlight as well
  //ledcSetup(0, 12000, 8);
  //ledcAttachPin(0, 0);
  //ledcWrite(0, 255);

  //pinMode(2, OUTPUT);
  //digitalWrite(2, HIGH);

  preferences.begin("EDFuelLCD",false);
  hyperchargetime = preferences.getULong("hyperchargetime", 15000);
  scchargetime = preferences.getULong("scchargetime", 4000);
  cooldowntime = preferences.getULong("cooldowntime", 6000);
  brightnesson = preferences.getUChar("brightnesson", 255);
  brightnessoff = preferences.getUChar("brightnessoff", 50);

  mutex = xSemaphoreCreateMutex();
  unsigned long cmills;
  unsigned long pmills;

  WiFi.mode(WIFI_STA);

//  Serial.begin(115200);
//  while(!Serial) delay(10);
  smartdisplay_init();

  ui_init();

  String passset = String(lv_label_get_text(ui_lblWifiInfo));
  passset.replace("*PASS*", wifiInitialApPassword);
  lv_label_set_text(ui_lblWifiInfo, passset.c_str());
//  Serial.print("ss");
  lv_disp_load_scr(ui_screenWiFiConfig);
  lv_obj_add_flag(ui_lblWifiInfo, LV_OBJ_FLAG_HIDDEN);
  lv_timer_handler();

//  Serial.print("se");
    // queues for passing info between tasks
  QueueHandle = xQueueCreate(10, sizeof(fueldata_t));
  //quFlags = xQueueCreate(1, sizeof(flags_t));
  quFlags = xSemaphoreCreateMutex();

  // Check if the queue was successfully created
  if (QueueHandle == NULL || quFlags == NULL) {
//    Serial.println("Queue could not be created. Halt.");
    while (1) {
      delay(1000);  // Halt at this point as is not possible to continue
    }
  }
  
  if (!LittleFS.begin(false, "/littlefs")) {
//    Serial.print("Error opening storage filesystem");
  }
  if (LittleFS.exists("/img/elite-dangerous-logo.png")) {
//    Serial.println("Logo found");
  } else {
//    Serial.println("Logo NOT found");
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
//    Serial.printf("New Fuel Level = %0.2f\r\n", fuel_info.fuellevel);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // fuel tank size update
  server.on(UriBraces("/fueltank/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.fuelcap = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
//    Serial.printf("New Fuel Capacity = %0.2f\r\n", fuel_info.fuelcap);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // resrv level update
  server.on(UriBraces("/res/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.reslevel = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
//    Serial.printf("New res Level = %0.2f\r\n", fuel_info.fuellevel);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // resrv capacity
  server.on(UriBraces("/restank/{}"), []() {
    String value = server.pathArg(0);
    fuel_info.rescap = value.toFloat();
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
//    Serial.printf("New res cap = %0.2f\r\n", fuel_info.fuellevel);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // backlight request
  server.on(UriBraces("/light/{}"), []() {
    String value = server.pathArg(0);
    value.toLowerCase();
    fuel_info.light = (value == "on"?true:false);
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    if (fuel_info.light) {
    //  ledcWrite(0, brightnesson);
      smartdisplay_lcd_set_backlight((float)brightnesson/255.0);
    } else {
    //  ledcWrite(0, brightnessoff);
    smartdisplay_lcd_set_backlight((float)brightnessoff/255.0);
    }
    
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });  
  // backlight brightness control 0-255
  server.on("/bright", []() {
    if (server.hasArg("level")) {
      float level = server.arg("level").toFloat();
      if (level > 255) level= 255;
      if (level < 0) level = 0;
      smartdisplay_lcd_set_backlight((float)(level/255.0));
    }
    if (server.hasArg("on")) {
      int level = server.arg("on").toInt();
      if (level > 255) level= 255;
      if (level < 0) level = 0;
      brightnesson = level;
      preferences.putUChar("brightnesson", level);
    }
    if (server.hasArg("off")) {
      int level = server.arg("off").toInt();
      if (level > 255) level= 255;
      if (level < 0) level = 0;
      brightnessoff = level;
      preferences.putUChar("brightnessoff", level);

    }
    String responseText = "<html><head></head><body><p><b>Current Brightness settings</b><br/>On = "
      +String(brightnesson)
      +"<br/>Off = " + String(brightnessoff)
      +"</p><hr/><p>setting values<br/>?level=[0-255] - set current level<br/>"
      +"?on=[0-255]  - set on level<br/>"
      +"?off=[0-255] - set off level</p></body></html>";
    server.send(200, "text/html", responseText);

  });
  // level & light update in one get request
  server.on("/data", []() {
    fuel_info.fuellevel = server.arg("fuel").toFloat();
    fuel_info.reslevel = server.arg("res").toFloat();
    fuel_info.fuelcap = server.arg("fueltank").toFloat();
    fuel_info.rescap = server.arg("restank").toFloat();
    String value =  server.arg("light");
//    Serial.printf("args\r\nfuel: %s\r\nres: %s\r\nfueltank: %s\r\nrestank: %s\r\n------\r\n", 
//        server.arg("fuel"), 
//        server.arg("res"), 
//        server.arg("fueltank"),
//        server.arg("restank"));
    value.toLowerCase();
    fuel_info.light = (value=="on"?true:false);
    memcpy(&(fuel_info.flags), &flag_info, sizeof(flags_t));
    xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    //handleRoot();
    server.send(200, "text/html", "<html><head></head><body><p>OK</p></body></html>");
  });

  // flags
  server.on("/flags", []() {
    xSemaphoreTake(quFlags, portMAX_DELAY);
    flag_info.flags = server.arg("flags").toInt();
    xSemaphoreGive(quFlags);
    flag_info.flags2 = server.arg("flags2").toInt();
    flag_info.cmdtime = millis();
    memcpy(&fuel_info.flags, &flag_info, sizeof(flags_t));
    /*xQueueSend(QueueHandle, &fuel_info, portMAX_DELAY);
    while (!xQueueSend(quFlags, &flag_info, 0)) {
      flags_t flagdump;
      xQueueReceive(quFlags, &flagdump, 0);
    }*/
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
  // -- End of URL handlers

  server.on("/timers",[]() {
    if (server.hasArg("hyper")) {
      xSemaphoreTake(quFlags, portMAX_DELAY);
      hyperchargetime = server.arg("hyper").toInt();
      preferences.putULong("hyperchargetime",hyperchargetime);
      xSemaphoreGive(quFlags);
    }
    if (server.hasArg("super")) {
      xSemaphoreTake(quFlags, portMAX_DELAY);
      scchargetime = server.arg("super").toInt();
      preferences.putULong("scchargetime",scchargetime);
      xSemaphoreGive(quFlags);
    }
    if (server.hasArg("cool")) {
      xSemaphoreTake(quFlags, portMAX_DELAY);
      cooldowntime = server.arg("cool").toInt();
      preferences.putULong("cooldowntime",cooldowntime);
      xSemaphoreGive(quFlags);
    }
    xSemaphoreTake(quFlags, portMAX_DELAY);
    String responsetext = "<html><head></head><body><p><b>Current timers</b><br/>hyper = " 
      + String(hyperchargetime)
      +"<br/>super = " + String(scchargetime)
      +"</br>cool = " + String(cooldowntime)
      +"</p></body></html>";
    xSemaphoreGive(quFlags);
    server.send(200,"text/html",responsetext);

  });


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
  
  //xQueueSend(quFlags, &flag_info, 1);

  xTaskCreatePinnedToCore( ledFlagBlink, "blink", 3000, NULL, 1, &tskBlink, xPortGetCoreID() );
  xTaskCreatePinnedToCore( updateDisplay, "display", 3000, NULL, 1, &tskDisplay, xPortGetCoreID() );
//  Serial.println("Ready.");
}


void loop() {
    iotWebConf.doLoop();
    //updateDisplay(NULL);
    //ledFlagBlink(NULL);
    LOCK;
    lv_timer_handler();
    RELEASE;
    
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
        if (activescreen != ui_ScreenFuel) {
          //lv_disp_load_scr(ui_ScreenFuel);
          LOCK;
          switchToScreen(ui_ScreenFuel);
          RELEASE;
        }
        f = fuelinfo.fuellevel;
        fc = fuelinfo.fuelcap;
        r = fuelinfo.reslevel;
        rc = fuelinfo.rescap;

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
    if (xSemaphoreTake(quFlags, 5)) {
      memcpy(&flags, &flag_info, sizeof(flags_t));
      xSemaphoreGive(quFlags);
    }
    //memcpy(&flags, &prevflags, sizeof(flags_t));
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
        xSemaphoreTake(quFlags, portMAX_DELAY);
        fsdchargetime = (flags.flags2 & edflags2::HyperdriveCharging)?hyperchargetime:scchargetime;
        xSemaphoreGive(quFlags);
//        Serial.printf("Started CHarging %d (flags:%d)\r\n", fsdchargetime, flags.flags2);
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
//        Serial.println("cooldown");      
        LOCK;
        lv_arc_set_value(ui_spinCharging, 100);
        RELEASE;
        currentPercent = 100;
        msCooldown = flags.cmdtime;
      }
      xSemaphoreTake(quFlags, portMAX_DELAY);
      currentPercent = 100-(uint16_t)(((currentMs-msCooldown)*100)/cooldowntime);  // should be 10s
      xSemaphoreGive(quFlags);
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
        lv_obj_clear_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);
        RELEASE;
      }
      /*blinking = true;
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
      }*/
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
          <p><b>Extra Info bits</b><br/>/name?name=&lt;text&gt;  - update name at top of fuel display<br /> - status.json flag values<br/>/flags?flags=&lt;value&gt;&flags2=&lt;value&gt;<br/>
          <hr /><h2>Extra functions</h2>
          <ul><li>/reboot - <b>reboot without confirmation</b></li>
          <li><a href="/config">/config</a> - WiFi configuration</li>
          <li><a href="/timers">Jump/cooldown timers for the arc</a></li>
          <li><a href="/bright">On/Off backlight levels</a></li>
          </ul>
          
          </body></html>
  )";
  response.replace("FUELLEVEL", String(fuel_info.fuellevel,2));
  response.replace("FUELTANK", String(fuel_info.fuelcap,2));
  response.replace("RESRV", String(fuel_info.reslevel,3));
  response.replace("RESTANK", String(fuel_info.rescap, 2));
  server.send(200, "text/html", response);
}