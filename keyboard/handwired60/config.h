#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1010
#define DEVICE_VER      0x0002
#define MANUFACTURER    Ramiel
#define PRODUCT         RMPad
#define DESCRIPTION     t.m.k. keyboard firmware for RMPad

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE   5 

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */

#define IS_COMMAND() ( \
    matrix_is_on(0, 0) && matrix_is_on(0, MATRIX_COLS - 1) \
)

#endif
