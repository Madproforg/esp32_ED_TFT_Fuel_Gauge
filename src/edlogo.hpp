#ifndef __EDLOGO_INCLUDED__
#define __EDLOGO_INCLUDED__
#include <Arduino.h>

typedef struct {
    uint8_t id;
    uint32_t len;
    const char *mime;
    const uint8_t data[];
} memfile;

extern memfile edlogo;

#endif