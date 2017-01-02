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
        P7,  P8,  P9,  PPLS, \
        P4,  P5,  P6,  PMNS, \
        P1,  P2,  P3,  PAST, \
        P0,  COMM,PDOT,ENT)
};

const action_t PROGMEM fn_actions[] = {};
