// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap.h"
#include "accented_letters.h"
#include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 50;
        case HOME_S:
            return TAPPING_TERM + 50;
        /* case HOME_D: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_F: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_G: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_H: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_J: */
        /*     return TAPPING_TERM - 20; */
        /* case HOME_K: */
        /*     return TAPPING_TERM - 20; */
        case HOME_L:
            return TAPPING_TERM + 50;
        case HOME_SCLN:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /*Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,                          KC_Y,          KC_U,    KC_I,    KC_O,    KC_P    ,
    HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                        KC_H,        HOME_J,  HOME_K,  HOME_L,  LT(_MOUSE,KC_SCLN),
    KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    _______, _______,    KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_VOLU, KC_PAUS, KC_VOLD, KC_DEL,MO(_SYMBOLS),_______, _______,LT(_NUMBERS,KC_SPC),KC_BSPC, _______, _______, _______
  ),
 [_MOUSE] = LAYOUT(
    _______,KC_MS_BTN1,  _______,     KC_MS_BTN2,  KC_MS_ACCEL2,                   _______,_______,   KC_MS_UP,  _______,    _______,
    _______,KC_LALT,     KC_LCTL,     KC_LSFT,     KC_MS_ACCEL1,                   _______,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,_______,
    _______,C(KC_X),     C(KC_C),     C(KC_V),     KC_MS_ACCEL0, _______, _______, _______, _______,   _______,   _______,   _______,
    _______, _______,    _______,     _______,     _______,      _______, _______, _______, _______,  _______,   _______,    _______
  ),
  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_NUMBERS] = LAYOUT( /* [> RAISE <] */
    KC_1,    KC_2,     KC_3,   KC_4,   KC_5,                      KC_6,     KC_7,   KC_8,   KC_9, _______,
    _______, _______, _______,KC_PMNS, KC_PSLS,                   KC_NO,    KC_4,   KC_5,   KC_6, KC_DOT ,
    _______, _______, _______, KC_PPLS, KC_PAST,_______, _______, KC_0,     KC_1,   KC_2,   KC_3, KC_COMM ,
    _______, _______, _______, KC_DEL, MO(_NAV), KC_EQL,  _______, _______, _______, KC_BSPC, KC_0, KC_EQL 
  ),
  
  [_SYMBOLS] = LAYOUT(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                   _______, _______, _______, _______, _______, 
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                    KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, 
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, 
    _______,_______ , _______, _______, _______, _______,_______,  MO(_NAV),  _______, _______, _______,_______
    ),

  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10  
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_NAV] = LAYOUT( /* [> LOWER <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,        KC_F7,        KC_F8,      KC_F9,        KC_F10  ,
    _______, _______, _______, _______, _______,                   KC_LEFT,      KC_DOWN,      KC_UP,      KC_RGHT,      _______ ,
    _______, _______, _______, _______, _______, _______, _______, G(C(KC_LEFT)),G(C(KC_DOWN)),G(C(KC_UP)),G(C(KC_RGHT)),_______  ,
    _______, _______, _______, _______, _______, _______, _______, _______,      _______,      _______,     _______,    _______
    ),
};
