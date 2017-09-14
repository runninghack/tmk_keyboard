#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "backlight.h"
#include "softpwm_led.h"
#include "action.h"


void backlight_enable(void);
void backlight_disable(void);
inline void backlight_set_raw(uint8_t raw);

static const uint8_t backlight_table[] PROGMEM = {
    0, 16, 128, 255
};

extern backlight_config_t backlight_config;
uint8_t backlight_brightness;


void backlight_set(uint8_t level)
{

    softpwm_enable();

    switch (level) {
        case 1:
        case 2:
        case 3:
            softpwm_led_enable_all();
            fading_led_disable_all();
            breathing_led_disable_all();
            backlight_brightness = pgm_read_byte(&backlight_table[level]); /* read backlight_table from flash to ram*/
            backlight_set_raw(backlight_brightness);
            break;
        case 4:
        case 5:
        case 6:
            softpwm_led_enable_all();
            fading_led_disable_all();
            breathing_led_enable_all();
            breathing_led_set_duration(6 - level);
            break;
        case 7:
            softpwm_led_enable_all();
            fading_led_enable_all();
            breathing_led_disable_all();
            fading_led_set_direction_all(FADING_LED_FADE_IN);
            fading_led_set_duration(3);
            break;
        case 8:
            softpwm_led_enable_all();
            fading_led_enable_all();
            breathing_led_disable_all();
            fading_led_set_direction_all(FADING_LED_FADE_OUT);
            fading_led_set_duration(3);
            break;
        case 0:
        default:
            fading_led_disable_all();
            breathing_led_disable_all();
            backlight_brightness = 0;
            backlight_set_raw(backlight_brightness);
            softpwm_led_disable_all();
            break;
    }
}


inline void backlight_set_raw(uint8_t raw)
{
    softpwm_led_set_all(raw);
}

void action_keyevent(keyevent_t event)
{
    if (backlight_config.enable) {
        if (backlight_config.level == 7) {
            if (event.pressed) {
                fading_led_set_delay_all(64);
                softpwm_led_decrease_all(32);
            }
        }
        if (backlight_config.level == 8) {
            if (event.pressed) {
                fading_led_set_delay_all(64);
                softpwm_led_increase_all(32);
            }
        }
    }
}



