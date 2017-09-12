#include "keymap_common.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: Default Layer */
    KEYMAP(
    		  HPR_TAB, Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    BSPC, \
    		  CTL_ESC, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT, \
    		  LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, SFT_ENT, \
    		  MEH_GRV, LCTL, LALT, LGUI, LOWER,   SPC,  SPC,  RAISE,   LEFT, DOWN, UP,   RGHT),
    /* 1: Lower Layer */
    KEYMAP(
    		0,          1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    DEL, \
			_______,    F1,   F2,   F3,   F4,   F5,   F6,   4,    5,    6,    _______, _______, \
    		_______,    F7,   F8,   F9,   F10,  F11,  F12,  1,    2,    3,    _______, _______, \
			_______,    _______, _______, _______, _______, _______, _______, _______, MNXT, VOLD, VOLU, MPLY),
};


#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),                // to Fn overlay
    [1] = ACTION_BACKLIGHT_TOGGLE(),                // BackLight TOGGLE 
    [2] = ACTION_BACKLIGHT_DECREASE(),              // BackLight -      
    [3] = ACTION_BACKLIGHT_INCREASE(),              // BackLight +      
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    
}
