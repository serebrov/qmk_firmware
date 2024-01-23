//Tap Dance Declarations
enum {
  TD_CTRL_AT = 0
  TD_ALT_LEFT_PAR = 0
  TD_LT2_RIGHT_PAR = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
TD(TD_ESC_CAPS)

// const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {COMBO(esc_combo, KC_ESC)};
