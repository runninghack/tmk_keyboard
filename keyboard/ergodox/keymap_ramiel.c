/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <util/delay.h>
#include "bootloader.h"
#include "keymap_common.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        ESC, 1,   2,   3,   4,   5,   GRV,
        TAB, Q,   W,   E,   R,   T,   FN2,
        LCTL,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   FN1,
        LCTL,LGUI, LALT,UP,DOWN,
                                      MINS, EQL,
                                            FN5,
                                 SPC, BSPC, FN6,
        // right hand
             F12, 6,   7,   8,   9,   0, DELETE,
             FN4, Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN3, N,   M,   COMM,DOT, SLSH, FN7,
                       LEFT,RGHT,UP,  HOME, END,
        LBRC,RBRC,
        PGUP,
        PGDN,F5, ENT
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key
    [1] = ACTION_MODS_KEY(MOD_LGUI,KC_LEFT),              // FN1 - 
    [2] = ACTION_LAYER_MOMENTARY(1),                      // FN2 - 
    [3] = ACTION_MODS_KEY(MOD_LGUI,KC_RIGHT),             // FN3 -  
    [4] = ACTION_LAYER_MOMENTARY(1),                      // FN4 - set Layer0
    [5] = ACTION_MODS_KEY(MOD_LGUI,KC_A),
    [6] = ACTION_MODS_KEY(MOD_LGUI,KC_W),
    [7] = ACTION_MODS_KEY(MOD_LALT,KC_TAB),
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
