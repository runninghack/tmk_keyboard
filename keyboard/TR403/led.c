#include <avr/io.h>
#include "stdint.h"
#include "led.h"


#ifndef LEDMAP_ENABLE
/* LED pin configuration
 * CapsLock: PC7
 */
void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRC |= (1<<PC7);
        PORTC &= ~(1<<PC7);
    } else {
        // Hi-Z
        DDRC &= ~(1<<PC7);
        PORTC &= ~(1<<PC7);
    }
}
#endif
