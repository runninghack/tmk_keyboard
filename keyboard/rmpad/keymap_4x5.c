#include "keymap_common.h"

// 4x5 Keypad
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Keymap 0: Default Layer
     * ,---------------.
     * |Esc|Tab|F5 |Bs |
     * |---+---+---+---|
     * |7  |8  |9  |+  |
     * |---+---+---+---|
     * |4  |5  |6  |-  |
     * |---+---+---+---|
     * |1  |2  |3  |*  |
     * |---+---+---+---|
     * |0  | , |.  |Ent|
     * `---------------'
     */
    [0] = KEYMAP(
        ESC, TAB, F5,  BSPC, \
        7,  8,  9,  PPLS, \
        4,  5,  6,  PMNS, \
        1,  2,  3,  PAST, \
        0,  COMM,DOT,ENT)
};

const action_t PROGMEM fn_actions[] = {};
