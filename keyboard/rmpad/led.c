#include <avr/io.h>
#include "stdint.h"
#include "led.h"

#ifndef LEDMAP_ENABLE

void led_set(uint8_t usb_led)
{}

#endif
