#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "keymap_common.h"


const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: Default Layer */
    KEYMAP(
    		  TAB, Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    BSPC, \
    		  ESC, A,    S,    D,    F,    G,    H,    J,    K,    L,          QUOT, \
    		  LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, ENT, \
    		  LCTL, LALT, LGUI,  SPC,                      FN0,   LEFT, DOWN, UP,   RGHT),
    /* 1: Lower Layer */
    KEYMAP(
    		0,       1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    DEL, \
		TRNS,    F1,   F2,   F3,   F4,   F5,   F6,   4,    5,    6,          TRNS, \
    		TRNS,    F7,   F8,   F9,   F10,  F11,  F12,  1,    2,    3,    TRNS, TRNS, \
		TRNS,    TRNS, TRNS, TRNS,                       TRNS, MNXT, FN1, FN2, FN3),
};


const uint16_t fn_actions[] PROGMEM = {
    [0] = ACTION_LAYER_MOMENTARY(1),                // to Fn overlay
    [1] = ACTION_BACKLIGHT_TOGGLE(),                // BackLight TOGGLE 
    [2] = ACTION_BACKLIGHT_DECREASE(),              // BackLight -      
    [3] = ACTION_BACKLIGHT_INCREASE(),              // BackLight +      
};
