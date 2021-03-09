/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _SYM,
    _NAV,
    _FN,
    _NUM,
    _MOUSE,
    _ADJUST
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define SHFT_Z MT(MOD_LSFT, KC_Z)
#define SHIFT_SLASH MT(MOD_RSFT,KC_SLSH)
#define CTRL_A MT(MOD_LCTL,KC_A)
#define PREVWINDOW MT(MOD_LCTL, KC_LEFT)
#define NEXTWINDOW MT(MOD_LCTL, KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * General design considerations:
 *
 * - Based on Auto-Shift (hold the key longer to access the shifted version)
 * - Mods are on thumbs
 * - Special keys (Esc, Tab, etc) are on stronger fingers instead of pinky
 * - Symmetric: Space and Sym keys are both on the left and right, so it is possible to alter hands when typing
 *   - For example, to enter -, tap Sym on the left and `j` on the right.
 *   - Or use right space when typing "test test " ("t" is on the left, space is on the right) and use
 *   left space for "key key" ("y" is on the right, space is on the left)
 * - Main mods (Ctrl, Sym, Shift are one-shot)
 *
 * Notes:
 *
 * - Most important layers are base and Sym that give access to letters, numbers and symbols.
 * - Enter is on the right in the middle row and ; is moved to the Sym layer.
 * - Another essential layer is Nav where there are Tab, Esc, Backspace, Arrow keys and other navigation stuff, it is available by
 *   holding left Space key (arrows are on the right, backspace is by tapping the right space while holding left)
 * - There is an OSL Shift on the right, but it is just for backup, the Shift key is not needed in most cases due to AutoShift.
 * - Main mods (Sym layer, Ctrl and Shift) are one-shot - we can tap it without holding and it will be applied to the next keypress.
 * - The `.` is a dual-function Alt (Alt on hold, dot on tap). Currently QMK does not support Auto-Shift for dual-function
 * keys, but this is not important since shifted "." is "<" which is available on the Sym layer (on the left).
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | Enter|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |   ,  | . Alt|   /  |        |
 * `----------------------+------+------+------+ Space|Space |  |Space | Space+------+------+------+----------------------'
 *                        |      | OSM  | OSL  |      |      |  |      |      | OSL  | OSL  |      |
 *                        |      | CTRL | Sym  | Nav  |Adjust|  |Adjust| Mouse| Sym  | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_NO, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           KC_NO,
      KC_NO, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    RGUI_T(KC_ENT), KC_NO,
      KC_NO, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, KC_N,    KC_M,    LALT_T(KC_COMM), KC_DOT,  KC_SLSH, KC_NO,
           KC_NO, OSM(MOD_LCTL), OSL(1), LT(2,KC_SPC), LT(_ADJUST,KC_SPC),       LT(_ADJUST,KC_SPC), LT(5,KC_SPC), OSL(1), OSM(MOD_RSFT), KC_NO
    ),
/*
 * Sym Layer: Numbers and Symbols
 * 
 * Note: !@#$% anD ^&*() are available via AutoShift + numbers.
 *
 * Note: Bottom row has shifted versions of the symbols from the middle row. So it can be empty with
 * shifted versions of symbols entered via AutoShift, but I find it a bit faster and more convenient
 * the way it is, it is also easy to remember since this is how it works on a regular keyboard.
 * Exception are angle brackets (`<` and `>`) that are under parentesis (`(` and `)`) on the left.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  `   |  (   |  )   |  '   |  =   |                              |   \  |  -   |  [   |  ]   |  ;   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ~   |  <   |  >   |  "   |  +   |      |      |  |      |      |   |  |  _   |  {   |  }   |  :   |        |
 * `----------------------+------+------+------+ Space|Space |  |Space | Space+------+------+------+----------------------'
 *                        |      | OSM  | OSL  |      |      |  |      |      | OSL  | OSL  |      |
 *                        |      | CTRL | Sym  | Nav  |Adjust|  |Adjust| Mouse| Sym  | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, KC_1, KC_2, KC_3, KC_4, KC_5,                                                KC_6, KC_7, KC_8, KC_9, KC_0, _______,
      _______, KC_GRV, KC_LPRN, KC_RPRN, LT(4,KC_QUOT), KC_EQL,                             KC_BSLS, LT(3,KC_MINS), KC_LBRC, KC_RBRC, KC_SCLN, _______,
      _______, KC_TILD, KC_LT, KC_GT, KC_DQUO, KC_PLUS, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_LCBR, KC_RCBR, KC_COLN, _______,
                                 _______, KC_TRNS, KC_TRNS, KC_BSPC, _______,  _______,  KC_BSPC, KC_TRNS, KC_TRNS, _______
    ),
/*
 * Nav Layer: Arrows, Tab, Esc, Backspace and window-management shortcuts.
 *
 * Note: the Nav layer is available while holding the left Space key, I find it quite easy to access main navigation keys:
 * - Left Space + F = Tab
 * - Left Space + G = Esc
 * - Left Space + Right Space = Backspace
 * - Left Space + B = CapsLock (I use it as an input language switch)
 * - Left Space + hjkl = Arrows
 *
 * Note: I use GUI+1,2,3,4,5 to switch between virtual desktops a I use GUI+O to show the floating terminal - these
 * are the shortcuts on the right side.
 *
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |GUI+1 |GUI+2 |GUI+3 |GUI+4 |GUI+5 |                              | Home | PgUp |PgDown| END  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |GUI+O | Tab  | Esc  |                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Del  | Caps |      |      |  |      |      |A-Left|      |      |A-Right|      |        |
 * `----------------------+------+------+------+ Space|Space |  |Space | Space+------+------+------+----------------------'
 *                        |      | OSM  | OSL  |      |      |  |      |      | OSL  | OSL  |      |
 *                        |      | CTRL | Sym  | Nav  |Adjust|  |Adjust| Mouse| Sym  | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5),                      KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO,    _______,
      _______, KC_NO, KC_NO, RGUI(KC_O), KC_TAB, KC_ESC,                                        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, _______,
      _______, KC_NO, KC_NO, KC_NO, KC_DEL, KC_CAPS,        _______, _______, _______, _______, LALT(KC_LEFT), KC_NO, KC_NO, RALT(KC_RGHT), KC_NO, _______,
                                 _______, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_BSPC, KC_TRNS, KC_TRNS, _______
    ),
/*
 * Fn Layer: function keys (on the left), the layer is accessed by holding right Sym and J.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  | F10  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |  F11 | F12  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+ Space|Space |  |Space | Space+------+------+------+----------------------'
 *                        |      | OSM  | OSL  |      |      |  |      |      | OSL  | OSL  |      |
 *                        |      | CTRL | Sym  | Nav  |Adjust|  |Adjust| Mouse| Sym  | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FN] = LAYOUT(
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    _______,
      _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
      _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12,   _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
                                 _______, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_BSPC, KC_TRNS, KC_TRNS, _______
    ),
/*
 * Num Layer: numpad (on the right), the layer is accessed by holding left Sym and F.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |   *  |   7  |   8  |   9  |  /   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |  F   |                              |   -  |   4  |   5  |   6  |  ;   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   =  |   3  |   2  |   1  |  +   |        |
 * `----------------------+------+------+------+ Space|Space |  |Space | Space+------+------+------+----------------------'
 *                        |      | OSM  | OSL  |      |      |  |      |      |   0  |   .  |      |
 *                        |      | CTRL | Sym  | Nav  |Adjust|  |Adjust| Mouse|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_PAST, KC_P7, KC_P8, KC_P9, KC_PSLS, _______,
      _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_PMNS, KC_P4, KC_P5, KC_P6, KC_TRNS, _______,
      _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, _______, KC_PEQL, KC_P1, KC_P2, KC_P3, KC_PPLS, _______,
                                 _______, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_TRNS, KC_P0, KC_PDOT, _______
    ),
/*
 * Mouse Layer: mouse keys (on the right, WASD-style), mouse wheel keys (on the left, WASD) the layer is accessed by holding right space.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |MW Dwn|      |      |                              |      |      | M Up|        |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+-------+------+--------|
 * |        |      |MW Lft|MW Up |MW Rgt|      |                              |      |M Left|M Down|M Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+-------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |       |      |        |
 * `----------------------+------+------+------+      |Space |  |Space | Space+------+------+------+-----------------------'
 *                        |      | OSM  | Mouse| Mouse|      |  |      |      | OSL  | OSL  |      |
 *                        |      | CTRL | Btn 1| Btn2 |Adjust|  |Adjust| Mouse| Sym  | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, KC_NO, KC_NO,   KC_WH_D, KC_NO, KC_NO,                                      KC_NO, KC_NO, KC_MS_U, KC_NO, KC_PSCR,  _______,
      _______, KC_NO, KC_WH_L, KC_WH_U, KC_WH_R, KC_NO,                                    KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, _______,
      _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      _______, _______, _______, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______,
                            _______, KC_TRNS, KC_BTN1, KC_BTN2, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, _______
    ),
/*
 * Adjust Layer: keyboard settings, adjusted by holding inner thumb keys (inner Space).
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RGB Mode|RGB Tog|RGB Next|     |     |     |                              |      |      |      |      |      |        |
 * |--------+-------+--------+-----+-----+-----|                              |------+------+------+------+------+--------|
 * |Hue Inc |Hue Dec|        |     |     |     |                              |      |      |      |      |      |        |
 * |--------+-------+--------+-----+-----+-----+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |       |        |     |     |     |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+      |Space |  |Space | Space+------+------+------+----------------------'
 *                        |      | OSM  | Mouse| Mouse|      |  |      |      | OSL  | OSL  |      |
 *                        |      | CTRL | Btn 1| Btn2 |Adjust|  |Adjust| Mouse| Sym  | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      RGB_RMOD,RGB_TOG, RGB_MODE_FORWARD, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______,
      RGB_HUI, RGB_HUD, KC_NO, KC_NO, KC_NO, KC_NO,                                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______,
      RGB_SAI, RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO,        _______, _______, _______, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______,
                                 _______, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, _______
    ),
/*
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        /* case _ADJUST: */
        /*     oled_write_P(PSTR("Adjust\n"), false); */
        /*     break; */
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            // tap_code(KC_VOLU);
            tap_code(KC_LEFT);
        } else {
            // tap_code(KC_VOLD);
            tap_code(KC_RIGHT);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            for (uint8_t idx = 0; idx < 5; idx++) {
                tap_code(KC_WH_U);
            }
        } else {
            for (uint8_t idx = 0; idx < 5; idx++) {
                tap_code(KC_WH_D);
            }
        }
    }
}
#endif
