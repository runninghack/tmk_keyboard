#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


/* RMPad keymap definition macro
 */
#define KEYMAP( \
    K0A, K0B, K0C, K0D, \
    K1A, K1B, K1C, K1D, \
    K2A, K2B, K2C, K2D, \
    K3A, K3B, K3C, K3D, \
    K4A, K4B, K4C, K4D  \
) { \
    { KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D }, \
    { KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D }, \
    { KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D }, \
    { KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D }, \
    { KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D }  \
}
#endif
