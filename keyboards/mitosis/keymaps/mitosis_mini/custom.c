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

enum tapdance_events {
    CT_SE,
    CT_CLN,
    CT_EGG,
    CT_FLSH,
    X_TAP_DANCE
};

void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            register_code16(KC_U);
        } else {
            register_code16(S(KC_U));
        }
    } else if (state->count == 2) {
        register_code16(KC_COLN);
    } else {
        register_code(KC_SCLN);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // unregister_code16(KC_U);
        /* if (state->interrupted || !state->pressed) { */
        /*     unregister_code16(KC_U); */
        /* } else { */
        unregister_code16(S(KC_U));
        /* } */
    } else if (state->count == 2) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
};

// const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {COMBO(esc_combo, KC_ESC)};
enum combo_events {
  JK_ESC,
  DF_TAB,
  QW_SFT,
  /* SD_LAYER, */
  /* KL_LAYER, */
  SD_CTRL,
  KL_CTRL,
  U_TD,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
// Interesting, via 1-key combo we can override the keymap in json.
const uint16_t PROGMEM u_combo[] = {KC_U, COMBO_END};

combo_t key_combos[] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [DF_TAB] = COMBO(df_combo, KC_TAB),
  [QW_SFT] = COMBO(qw_combo, KC_RSFT),
  [SD_CTRL] = COMBO(sd_combo, KC_LCTL),
  [KL_CTRL] = COMBO(kl_combo, KC_RCTL),
  [U_TD] = COMBO(u_combo, TD(CT_CLN)),
  /* [QW_SFT] = COMBO(qw_combo, OSM(KC_RSFT)), */
  /* [SD_LAYER] = COMBO(sd_combo, MO(_SYM)), */
  /* [SD_LAYER] = COMBO(sd_combo, OSL(_SYM)), */
  /* [KL_LAYER] = COMBO(kl_combo, OSL(_SYM)), */
};

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

