#ifndef CONFIG_H
#define CONFIG_H


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Triangle Lab
#define PRODUCT         TR660
#define DESCRIPTION     t.m.k. keyboard firmware for TR660 Keyboard

/* key matrix size */
#define MATRIX_ROWS 14
#define MATRIX_COLS 5

/* keymap in eeprom */
#define FN_ACTIONS_COUNT 32
#define KEYMAPS_COUNT 8
#define EECONFIG_KEYMAP_IN_EEPROM 0x11

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* number of backlight levels */
#ifdef BREATHING_LED_ENABLE
#ifdef FADING_LED_ENABLE
#define BACKLIGHT_LEVELS 8
#else
#define BACKLIGHT_LEVELS 6
#endif
#else
#define BACKLIGHT_LEVELS 3
#endif


/* enable customized backlight logic */
#define BACKLIGHT_CUSTOM
/* #define CUSTOM_LED_ENABLE */
/* #define RGB_LED_ENABLE */


/* LED mapping */
#ifdef LEDMAP_ENABLE
#define LED_COUNT 2
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#endif
