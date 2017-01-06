#ifndef RGB_H
#define RGB_H

#include <stdint.h>
#include <stdbool.h>

typedef union {
    uint8_t raw;
    struct {
        uint8_t level  :7;
        bool    enable :1;
    };
} rgb_config_t;

enum {
    RGB_OFF = 0,
    RGB_RED,
    RGB_YELLOW,
    RGB_GREEN,
    RGB_CYAN,
    RGB_BLUE,
    RGB_MAGENTA,
    RGB_WHITE,
    RGB_FADE,
    RGB_RAINBOW,
    RGB_LEVELS = RGB_RAINBOW
};

#define EECONFIG_RGB (uint8_t *)15
#define RGB_UNCONFIGURED 0xFF
#define RGB_LED_COUNT 24

void rgb_init(void);
void rgb_toggle(void);
void rgb_on(void);
void rgb_off(void);
void rgb_decrease(void);
void rgb_increase(void);
void rgb_step(void);
void rgb_set_brightness(uint8_t brightness);
void rgb_fading(void);

#endif
