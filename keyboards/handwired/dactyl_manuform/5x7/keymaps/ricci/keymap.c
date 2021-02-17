#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_5x7_ALT(
  // left hand
   KC_GRV,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_DEL,
   KC_MPLY,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_PGDN,
   KC_TAB,    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_PGUP,
   KC_MNXT,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
   KC_MPRV,   KC_MUTE, KC_VOLD, KC_VOLU,
                               KC_LGUI, KC_BSPC, KC_LALT,
                               KC_LCTL, KC_LSFT, TT(_FN),
        // right hand
                     KC_PSCR, KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                     KC_INS,  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                     RESET,   KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                              KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_EQL,
                                                KC_LBRC,  KC_RBRC,  KC_HOME,  KC_END,
        KC_RALT, KC_SPC,  KC_ENT,
        KC_ESC,  KC_RSFT, KC_LCTL),

[_FN] = LAYOUT_5x7_ALT(
  // left hand
   _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    RESET,
   _______,   _______,   _______,    KC_UP,    _______,   _______,  _______,
   _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______, _______,
                               _______, _______, _______,
        // right hand
                     _______,   KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,   _______,
                     _______,   _______,   _______,   _______,   _______,   _______,  _______,
                     _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______,  _______,
                                _______,   _______,   _______,   _______,   _______,  _______,
                                                      _______,   _______,   _______,  _______,
        _______, _______, _______,
        _______, _______, _______)

};
