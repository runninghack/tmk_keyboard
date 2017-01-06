#include <avr/io.h>
#include "stdint.h"
#include "led.h"


#ifndef LEDMAP_ENABLE
/* LED pin configuration
 * CapsLock: PB2
 */
void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRB |= (1<<2);
        PORTB &= ~(1<<2);
    } else {
        // Hi-Z
        DDRB &= ~(1<<2);
        PORTB &= ~(1<<2);
    }
}
#endif
