#include "keymap_common.h"

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
#ifndef KEYMAP_IN_EEPROM_ENABLE
    return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
#else
    return eeconfig_read_keymap_key(layer, key.row, key.col);
#endif
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return (action_t) {
#ifndef KEYMAP_IN_EEPROM_ENABLE
        .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)])
#else
        .code = eeconfig_read_keymap_fn_action(FN_INDEX(keycode))
#endif
    };
}

#ifdef KEYMAP_IN_EEPROM_ENABLE
const uint8_t* keymaps_pointer(void) {
    return (const uint8_t*)keymaps;
}

const uint16_t* fn_actions_pointer(void) {
    return fn_actions;
}
#endif
