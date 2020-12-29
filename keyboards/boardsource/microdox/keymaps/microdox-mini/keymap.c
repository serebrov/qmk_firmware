/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

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

#include QMK_KEYBOARD_H
#include "split_util.h"

enum layers {
    _QWERTY,
    _SYM,
    _NAV,
    _FN,
    _NUM,
    _MOUSE
};

#define KC_CTSC RCTL_T(KC_SCLN)
/* #define LOWER_SPC LT(_LOWER, KC_SPC) */
/* #define RASE_BACK LT(_RAISE, KC_BSPC) */
#define SHFT_Z MT(MOD_LSFT, KC_Z)
#define SHIFT_SLASH MT(MOD_RSFT,KC_SLSH)
/* #define RASE_ENT LT(_RAISE, KC_ENT) */
#define CTRL_A MT(MOD_LCTL,KC_A)
#define PREVWINDOW MT(MOD_LCTL, KC_LEFT)
#define NEXTWINDOW MT(MOD_LCTL, KC_RGHT)



/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {*/
/*   [_QWERTY] = LAYOUT_split_3x5_3(*/ 
/*         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,*/  
/*       CTRL_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_CTSC,*/ 
/*      SHFT_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, KC_COMM,  KC_DOT, SHIFT_SLASH,*/ 
/*                        MO(_LOWER),KC_LGUI, RASE_ENT,       RASE_BACK, LOWER_SPC, KC_TAB*/
/*     ),*/
/*   [_RAISE] = LAYOUT_split_3x5_3(*/ 
/*         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,*/ 
/*       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT,*/ 
/*      KC_LSFT, KC_GRV, PREVWINDOW, NEXTWINDOW, XXXXXXX,           KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,*/ 
/*                          _______, KC_LGUI, KC_ENT,           KC_BSPC,  KC_SPC, _______*/
/*                          ),*/
/*   [_LOWER] = LAYOUT_split_3x5_3(*/ 
/*        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,*/
/*        KC_ESC,   XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_DQT,*/ 
/*        KC_ESC,   KC_TILD, PREVWINDOW, NEXTWINDOW, RGB_MODE_FORWARD,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,*/ 
/*                             _______,  KC_LGUI,  KC_ENT,         KC_BSPC,  KC_SPC, _______*/
/*                             )*/
/* };*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, 
        KC_A, KC_S, KC_D, KC_F, KC_G,                                   KC_H, KC_J, KC_K, KC_L, RGUI_T(KC_ENT), 
        KC_Z, KC_X, KC_C, KC_V, KC_B,                                   KC_N, KC_M, LALT_T(KC_COMM), KC_DOT, KC_SLSH, 
            OSM(MOD_LCTL), OSL(1), LT(2,KC_SPC),                        LT(5,KC_SPC), OSL(1), OSM(MOD_RSFT)
    ),
	[_SYM] = LAYOUT_split_3x5_3(
        KC_1, KC_2, KC_3, KC_4, KC_5,                                   KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_GRV, KC_LPRN, KC_RPRN, LT(4,KC_QUOT), KC_EQL,                KC_BSLS, LT(3,KC_MINS), KC_LBRC, KC_RBRC, KC_SCLN, 
        KC_TILD, KC_LT, KC_GT, KC_DQUO, KC_PLUS,                        KC_PIPE, KC_UNDS, KC_LCBR, KC_RCBR, KC_COLN, 
            KC_TRNS, KC_TRNS, KC_BSPC,                                  KC_BSPC, KC_TRNS, KC_TRNS
    ),
	[_NAV] = LAYOUT_split_3x5_3(
        RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5),     KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, 
        KC_NO, KC_NO, RGUI(KC_O), KC_TAB, KC_ESC,                       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_DEL, KC_CAPS,                           LALT(KC_LEFT), KC_NO, KC_NO, RALT(KC_RGHT), KC_NO, 
                  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_BSPC, KC_TRNS, KC_TRNS
    ),
	[_FN] = LAYOUT_split_3x5_3(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                      KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_NUM] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_PAST, KC_P7, KC_P8, KC_P9, KC_PSLS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_PMNS, KC_P4, KC_P5, KC_P6, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_PEQL, KC_P1, KC_P2, KC_P3, KC_PPLS, 
                      KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_P0, KC_PDOT
    ),
	[_MOUSE] = LAYOUT_split_3x5_3(
        RGB_TOG, RGB_MODE_FORWARD, KC_WH_D, KC_NO, KC_NO,               KC_NO, KC_NO, KC_MS_U, KC_NO, KC_PSCR, 
        KC_NO, KC_WH_L, KC_WH_U, KC_WH_R, KC_NO,                        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
              KC_TRNS, KC_BTN1, KC_BTN2,                                KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef OLED_DRIVER_ENABLE
/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/*   if (!is_keyboard_master()) */
/*     return OLED_ROTATION_180; */
/*   return rotation; */
/* } */

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return isLeftHand ? OLED_ROTATION_180 : OLED_ROTATION_0;
}

/* uint32_t mode; */
void render_rgb_status(void) {

    /* if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) { */
    /*     snprintf(buf, sizeof(buf), " RGB %2d: %d,%d,%d ", */
    /*              rgblight_get_mode(), */
    /*              rgblight_get_hue()/RGBLIGHT_HUE_STEP, */
    /*              rgblight_get_sat()/RGBLIGHT_SAT_STEP, */
    /*              rgblight_get_val()/RGBLIGHT_VAL_STEP); */
    /*     oled_write(buf, false); */
    /* } else { */
    /*     oled_write_P( PSTR("\n"), false); */
    /* } */

    /* if (mode != rgblight_get_mode()) { */
    /*   oled_clear(); */
    /* } */
    /* mode = rgblight_get_mode(); */

    if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
      switch (rgblight_get_mode() ) {
          // See quantum/rgblight.h for the list of modes.
          case RGBLIGHT_MODE_STATIC_LIGHT:
              oled_write_P( PSTR("      LIGHT        "), false);
              break;
          case RGBLIGHT_MODE_BREATHING:
              oled_write_P( PSTR("      BREATHING    "), false);
              break;
          case RGBLIGHT_MODE_BREATHING + 1:
              oled_write_P( PSTR("      BREATHING 1  "), false);
              break;
          case RGBLIGHT_MODE_BREATHING + 2:
              oled_write_P( PSTR("      BREATHING 2  "), false);
              break;
          case RGBLIGHT_MODE_BREATHING + 3:
              oled_write_P( PSTR("      BREATHING 3  "), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_MOOD:
              oled_write_P( PSTR("      RAINB_MOOD   "), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_MOOD + 1:
              oled_write_P( PSTR("      RAINB_MOOD 1 "), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_MOOD + 2:
              oled_write_P( PSTR("      RAINB_MOOD 2 "), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_SWIRL:
              oled_write_P( PSTR("      RAINB_SWIRL  "), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_SWIRL + 1:
              oled_write_P( PSTR("      RAINB_SWIRL 1"), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_SWIRL + 2:
              oled_write_P( PSTR("      RAINB_SWIRL 2"), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_SWIRL + 3:
              oled_write_P( PSTR("      RAINB_SWIRL 3"), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_SWIRL + 4:
              oled_write_P( PSTR("      RAINB_SWIRL 4"), false);
              break;
          case RGBLIGHT_MODE_RAINBOW_SWIRL + 5:
              oled_write_P( PSTR("      RAINB_SWIRL 5"), false);
              break;
          case RGBLIGHT_MODE_SNAKE:
              oled_write_P( PSTR("      SNAKE        "), false);
              break;
          case RGBLIGHT_MODE_SNAKE + 1:
              oled_write_P( PSTR("      SNAKE 1      "), false);
              break;
          case RGBLIGHT_MODE_SNAKE + 2:
              oled_write_P( PSTR("      SNAKE 2      "), false);
              break;
          case RGBLIGHT_MODE_SNAKE + 3:
              oled_write_P( PSTR("      SNAKE 3      "), false);
              break;
          case RGBLIGHT_MODE_SNAKE + 4:
              oled_write_P( PSTR("      SNAKE 4      "), false);
              break;
          case RGBLIGHT_MODE_SNAKE + 5:
              oled_write_P( PSTR("      SNAKE 5      "), false);
              break;
          case RGBLIGHT_MODE_KNIGHT:
              oled_write_P( PSTR("      KNIGHT       "), false);
              break;
          case RGBLIGHT_MODE_KNIGHT + 1:
              oled_write_P( PSTR("      KNIGHT 1     "), false);
              break;
          case RGBLIGHT_MODE_KNIGHT + 2:
              oled_write_P( PSTR("      KNIGHT 2     "), false);
              break;
          case RGBLIGHT_MODE_CHRISTMAS:
              oled_write_P( PSTR("      X-MAS        "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT:
              oled_write_P( PSTR("      GRADIENT     "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 1:
              oled_write_P( PSTR("      GRADIENT 1   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 2:
              oled_write_P( PSTR("      GRADIENT 2   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 3:
              oled_write_P( PSTR("      GRADIENT 3   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 4:
              oled_write_P( PSTR("      GRADIENT 4   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 5:
              oled_write_P( PSTR("      GRADIENT 5   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 6:
              oled_write_P( PSTR("      GRADIENT 6   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 7:
              oled_write_P( PSTR("      GRADIENT 7   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 8:
              oled_write_P( PSTR("      GRADIENT 8   "), false);
              break;
          case RGBLIGHT_MODE_STATIC_GRADIENT + 9:
              oled_write_P( PSTR("      GRADIENT 9   "), false);
              break;
          case RGBLIGHT_MODE_ALTERNATING:
              oled_write_P( PSTR("      ALTERNATING  "), false);
              break;
          case RGBLIGHT_MODE_TWINKLE:
              oled_write_P( PSTR("      TWINKLE      "), false);
              break;
          case RGBLIGHT_MODE_TWINKLE + 1:
              oled_write_P( PSTR("      TWINKLE 1    "), false);
              break;
          case RGBLIGHT_MODE_TWINKLE + 2:
              oled_write_P( PSTR("      TWINKLE 2    "), false);
              break;
          case RGBLIGHT_MODE_TWINKLE + 3:
              oled_write_P( PSTR("      TWINKLE 3    "), false);
              break;
          case RGBLIGHT_MODE_TWINKLE + 4:
              oled_write_P( PSTR("      TWINKLE 4    "), false);
              break;
          case RGBLIGHT_MODE_TWINKLE + 5:
              oled_write_P( PSTR("      TWINKLE 5    "), false);
              break;
          case RGBLIGHT_MODE_RGB_TEST:
              oled_write_P( PSTR("      TEST         "), false);
              break;
          default:
              oled_write_P( PSTR("      OTHER        "), false);
              break;
      }
    }
}

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0
  };
  oled_write_P(qmk_logo, false);
}                                                                                 

static void render_status(void) {
   switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("^\n"), false);
      oled_write_P(PSTR("Layer: Base\n"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("  ^\n"), false);
      oled_write_P(PSTR("Layer: Sym\n"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("    ^\n"), false);
      oled_write_P(PSTR("Layer: Nav\n"), false);
      break;
    case _FN:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("      ^\n"), false);
      oled_write_P(PSTR("Layer: FN\n"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("        ^\n"), false);
      oled_write_P(PSTR("Layer: Num\n"), false);
      break;
    case _MOUSE:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("          ^\n"), false);
      oled_write_P(PSTR("Layer: Mouse\n"), false);
      break;
    /* case _ADJUST: */
    /*   oled_write_P(PSTR("B R L A O\n"), false); */
    /*   oled_write_P(PSTR("      ^\n"), false); */
    /*   oled_write_P(PSTR("Layer: Adjust\n"), false); */
    /*   break; */
    default:
      oled_write_P(PSTR("B S N F N M O\n"), false);
      oled_write_P(PSTR("            ^\n"), false);
      oled_write_P(PSTR("Layer: Other\n"), false);
  }
}

void oled_task_user(void) {
  if (isLeftHand) {
    render_logo();
    render_rgb_status();
    // When scroll is enabled, the RGB status is not refreshing,
    // only rendered once and updated after disconnecting and
    // connecting the keyboard back.
    // oled_scroll_left();
  } else {
    render_status();
  }
  /* if (is_keyboard_master()) { */
  /*   render_status(); */
  /* } else { */
  /*   /1* render_logo(); *1/ */
  /*   render_rgb_status(); */
  /*   oled_scroll_left(); */
  /* } */
}

#endif
