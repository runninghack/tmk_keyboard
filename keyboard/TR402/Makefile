# Target file name (without extension).
TARGET = TR40

# Directory common source filess exist
TMK_DIR = ../../tmk_core_custom

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC =	keymap_common.c \
	matrix.c \
	led.c \
	ledmap.c \
	backlight.c

ifdef KEYMAP
    SRC := keymap_$(KEYMAP).c $(SRC)
else
    SRC := keymap_default.c $(SRC)
endif


CONFIG_H = config.h


# MCU name
#MCU = at90usb1287
MCU = atmega32u4

# Processor frequency.
F_CPU = 16000000

#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Input clock frequency.
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT


# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# PCB Revision
ifdef REV
    OPT_DEFS += -DGH60_REV_$(REV)
endif

# Additional definitions from command line
ifdef DEFS
    OPT_DEFS += $(foreach DEF,$(DEFS),-D$(DEF))
endif

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes	# Audio control and System control(+450)
#CONSOLE_ENABLE = yes	# Console for debug(+400)
COMMAND_ENABLE = yes	# Commands for debug and configuration
#SLEEP_LED_ENABLE = yes	# Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	# USB Nkey Rollover
USB_6KRO_ENABLE = yes	# USB 6key Rollover
#PS2_MOUSE_ENABLE = yes	# PS/2 mouse(TrackPoint) support
#PS2_USE_BUSYWAIT = yes
BACKLIGHT_ENABLE = yes	# Enable keyboard backlight functionality
#KEYMAP_IN_EEPROM_ENABLE = yes # Read keymap from eeprom
#KEYMAP_SECTION_ENABLE = yes	# Fixed address keymap for keymap editor
SOFTPWM_LED_ENABLE = yes # Enable SoftPWM to drive backlight
FADING_LED_ENABLE = yes # Enable fading backlight
BREATHING_LED_ENABLE = yes # Enable breathing backlight
LEDMAP_ENABLE = yes		# Enable LED mapping
#LEDMAP_IN_EEPROM_ENABLE = yes # Read LED mapping from eeprom


# Optimize size but this may cause error "relocation truncated to fit"
#EXTRALDFLAGS = -Wl,--relax

# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
