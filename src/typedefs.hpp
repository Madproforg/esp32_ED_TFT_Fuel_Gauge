#ifndef EDFUEL_TYPEDEFS_INCLUDED
#define EDFUEL_TYPEDEFS_INCLUDED

typedef struct {
  uint32_t flags;
  uint32_t flags2;
  unsigned long cmdtime;
} flags_t;

enum extralcdcmds_t {
  cmdFuel = 0,
  cmdWiFiConfig,
  cmdWaitingForStartup
};
// fuel level struct for info passing between tasks
typedef struct {
  float fuellevel, fuelcap, reslevel, rescap;
  bool light;
  flags_t flags;
  extralcdcmds_t cmd;
} fueldata_t;
#endif