#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /*Layer 0*/
    KEYMAP(      ESC,  1,   2,   3,   4,   5,   6,   7,   8,   9,   0,    MINS, EQL, DELETE, BSPC,      \
                 TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,    LBRC, RBRC,ENT,    BSLS,      \
                 LCTL, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT, ENT,         PGUP,      \
                 LSFT, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, RSFT, CAPS,UP,     PGDN,      \
                 LCTL, LGUI,LALT,FN1, FN0, SPC,      FN2,      FN3, HOME, END,  LEFT,DOWN,   RIGHT      ),
    /*Layer 1*/
    KEYMAP(      F12,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,  F11,  F12, VOLU,  VOLD,       \
                 TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS,TRNS,  TRNS,       \
                 TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS,       TRNS,       \
                 TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS,TRNS,  TRNS,       \
                 TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS, TRNS, TRNS,TRNS,  TRNS        )
};

const action_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),                // to Fn overlay
  [1] = ACTION_MODS_KEY(MOD_LGUI,KC_LEFT),        // Left Workspace
  [2] = ACTION_LAYER_MOMENTARY(1),                // to Fn overlay
  [3] = ACTION_MODS_KEY(MOD_LGUI,KC_RIGHT),       // Right Workspace
};
