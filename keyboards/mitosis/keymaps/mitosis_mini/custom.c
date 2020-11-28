// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum mitosis_layers
{
	_BASE,
	_SYM,
	_NAV,
	_FN,
	_NUM,
	_MEDIA,
	_ADJUST,
	_ALERT
};

#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _BASE:
            set_led_off;
            break;
        case _SYM:
            set_led_off;
            break;
        case _NAV:
            set_led_off;
            break;
        case _FN:
            set_led_magenta;
            break;
        case _NUM:
            set_led_blue;
            break;
        case _MEDIA:
            set_led_red;
            break;
        case _ADJUST:
            set_led_red;
            break;
        case _ALERT:
            set_led_red;
            break;
        default:
            break;
    }
};

