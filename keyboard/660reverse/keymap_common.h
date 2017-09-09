#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "keymap_in_eeprom.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* GH60 keymap definition macro
 */
#define KEYMAP( \
               K000, K001, K002, K003, K004,    \
               K010, K011, K012, K013, K014,    \
               K020, K021, K022, K023, K024,    \
               K030, K031, K032, K033,          \
               K040, K041, K042, K043,          \
               K050, K051, K052, K053, K054,    \
               K060, K061, K062, K063,          \
               K070, K071, K072, K073, K074,    \
               K080, K081, K082, K083, K084,    \
               K090, K091, K092, K093, K094,    \
               K100, K101, K102, K103, K104,    \
               K110, K111, K112, K113, K114,    \
               K120, K121, K122, K123, K124,    \
               K130, K131, K132, K133, K134     \
) {  \
    { KC_##K000, KC_##K001, KC_##K002, KC_##K003, KC_##K004}, \
    { KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014}, \
    { KC_##K020, KC_##K021, KC_##K022, KC_##K023, KC_##K024}, \
    { KC_##K030, KC_##K031, KC_##K032, KC_##K033, KC_NO},     \
    { KC_##K040, KC_##K041, KC_##K042, KC_##K043, KC_NO},     \
    { KC_##K050, KC_##K051, KC_##K052, KC_##K053, KC_##K054}, \
    { KC_##K060, KC_##K061, KC_##K062, KC_##K063, KC_NO},     \
    { KC_##K070, KC_##K071, KC_##K072, KC_##K073, KC_##K074}, \
    { KC_##K080, KC_##K081, KC_##K082, KC_##K083, KC_##K084}, \
    { KC_##K090, KC_##K091, KC_##K092, KC_##K093, KC_##K094}, \
    { KC_##K100, KC_##K101, KC_##K102, KC_##K103, KC_##K104}, \
    { KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114}, \
    { KC_##K120, KC_##K121, KC_##K122, KC_##K123, KC_##K124}, \
    { KC_##K130, KC_##K131, KC_##K132, KC_##K133, KC_##K134}  \
}


#endif
