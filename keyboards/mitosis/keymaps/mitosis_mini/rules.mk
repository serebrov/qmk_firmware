SRC += custom.c

AUTO_SHIFT_ENABLE = yes

# Enable combos, see https://docs.qmk.fm/#/feature_combo?id=combos
# Combos do not work with autoshift
# https://github.com/qmk/qmk_firmware/issues/8136
# COMBO_ENABLE=yes

AUDIO_ENABLE = no # audio output
FAUXCLICKY_ENABLE = no
BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes	# Audio control and System control(+450)
CONSOLE_ENABLE = no	# Console for debug(+400)
COMMAND_ENABLE = no	# Commands for debug and configuration
UNICODE_ENABLE = no	# Unicode
BACKLIGHT_ENABLE = no	# Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no	# Enable Bluetooth with the Adafruit EZ-Key HID
MIDI_ENABLE = no	# MIDI controls
