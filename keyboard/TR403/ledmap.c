#include <avr/pgmspace.h>
#include "ledmap.h"


static const uint16_t ledmaps[LED_COUNT] PROGMEM = {
  [0] = LEDMAP_BACKLIGHT,                     // LED      - GPIO0 - PB7
  [1] = LEDMAP_CAPS_LOCK,                     // CapsLock         - PC7
};

ledmap_t ledmap_get_code(uint8_t index)
{
    return (ledmap_t) { .code = pgm_read_word(&ledmaps[index]) };
}

/* LED pin configration
 *   LED:       PB7
 *   CapsLock:  PC7
 */
void ledmap_led_init(void)
{
    DDRC  |= (1<<PC7);
    PORTC |= (1<<PC7);
    DDRB  |= (1<<PB7);
    PORTB |= (1<<PB7);
}

void ledmap_led_on(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB &= ~(1<<PB7);
            break;
        case 1:
            PORTC &= ~(1<<PC7);
            break;
    }
}

void ledmap_led_off(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB |= (1<<PB7);
            break;
        case 1:
            PORTC |= (1<<PC7);
            break;
    }
}
