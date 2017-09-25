#include <avr/pgmspace.h>
#include "keymap.h"
#include "keymap_in_eeprom.h"
#include "keymap_common.h"

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
  return eeconfig_read_keymap_key(layer, key.row, key.col);
 }

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
  return (action_t) {
    .code = eeconfig_read_keymap_fn_action(FN_INDEX(keycode))
      };
}

const uint8_t* keymaps_pointer(void) {
  return (const uint8_t*)keymaps;
}

const uint16_t* fn_actions_pointer(void) {
  return fn_actions;
}

