ENCODER_ENABLE = yes       # Enable the use of one or more encoders
TAP_DANCE_ENABLE = yes     # Activate tap dance

COMBO_ENABLE = yes 				 # Enable combos
NKRO_ENABLE = yes 				 # Enable NKRO: any number of key-presses at once
LTO_ENABLE = yes  				 # Enable Link Time Optimization
MOUSEKEY_ENABLE = yes      # Enable mouse keys
EXTRAKEY_ENABLE = yes      # Enable extra keys

SRC += combos.c			       # Source combos.c 

EXTRFLAGS += -flto

DEFAULT_FOLDER = atreus44/default
MCU = atmega32u4
BOOTLOADER = atmel-dfu
