#include "keymap_common.h"

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* 0: Default Layer */
    KEYMAP(
           ESC, TAB,  CAPS,LSFT, LCTL,          \
           1,   Q,    A,   Z,    LGUI,          \
           2,   W,    S,   X,    LALT,          \
           3,   E,    D,   C,                   \
           4,   R,    F,   V,                   \
           5,   T,    G,   B,    SPC,           \
           6,   Y,    H,   N,                   \
           7,   U,    J,   M,    FN1,           \
           8,   I,    K,   COMMA,RALT,          \
           9,   O,    L,   DOT,  RCTL,          \
           0,   P,    SCLN,SLSH, FN0,           \
           MINS,LBRC, QUOT,RSFT, LEFT,          \
           EQL, RBRC, ENT, UP,   DOWN,          \
           BSPC,BSLS, INS, DELETE,RIGHT),
    
    /* 1: Fn Layer */
    KEYMAP(
           TRNS, TRNS, TRNS,TRNS, TRNS,\
           F1,   TRNS, TRNS,TRNS, TRNS,\
           F2,   TRNS, TRNS,TRNS, TRNS,\
           F3,   TRNS, TRNS,TRNS,      \
           F4,   TRNS, TRNS,TRNS,      \
           F5,   TRNS, TRNS,TRNS, TRNS,\
           F6,   TRNS, TRNS,TRNS,      \
           F7,   TRNS, TRNS,TRNS, TRNS,\
           F8,   TRNS, TRNS,TRNS, TRNS,\
           F9,   TRNS, TRNS,TRNS, TRNS,\
           F10,  TRNS, TRNS,TRNS, TRNS,\
           F11,  TRNS, TRNS,TRNS, TRNS,\
           F12,  TRNS, TRNS,FN2,  FN3, \
           TRNS, TRNS, TRNS,FN1,  TRNS),
};

//MACRO 1~8
enum macro_id {
    MACRO_0,
    MACRO_1,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MACRO_6,
    MACRO_7,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case MACRO_0:
            return (event.pressed ?
             MACRO( T(8), T(3), T(4), T(3), T(7), T(4), T(7), D(LSFT), T(2), U(LSFT), T(Q), T(Q), T(DOT), T(C), T(O), T(M), W(100), END ) :
             MACRO( END ));
        case MACRO_1:
            return (event.pressed ?
             MACRO( D(LSFT), T(Z),D(LSFT), T(L), T(5), T(3), T(2), T(2), T(2), T(0), T(4), W(100), END ) :
             MACRO( END ));
        case MACRO_2:
            return (event.pressed ?
             MACRO( D(LSFT), T(Z),D(LSFT), T(L), T(5), T(3), T(2), T(2), T(2), T(0), T(4), END ) :
             MACRO( END ));
        case MACRO_3:
            return (event.pressed ?
             MACRO( END ) :
             MACRO( END ));
        case MACRO_4:
            return (event.pressed ?
             MACRO( END ) :
             MACRO( END ));
        case MACRO_5:
            return (event.pressed ?
             MACRO( END ) :
             MACRO( END ));
        case MACRO_6:
            return (event.pressed ?
             MACRO( END ) :
             MACRO( END ));
        case MACRO_7:
            return (event.pressed ?
             MACRO( END ) :
             MACRO( END ));
    }
    return MACRO_NONE;
}

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
