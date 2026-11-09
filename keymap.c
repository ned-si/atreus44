#include "nedsi.h"

// Atreus 44 physical layout on the 4x12 matrix: the top two rows have no keys
// in the two middle columns.
#define LAYOUT_atreus44( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) { \
  { k00, k01, k02, k03, k04, KC_NO, KC_NO, k05, k06, k07, k08, k09 }, \
  { k10, k11, k12, k13, k14, KC_NO, KC_NO, k15, k16, k17, k18, k19 }, \
  { k20, k21, k22, k23, k24, k25,   k26,   k27, k28, k29, k2a, k2b }, \
  { k30, k31, k32, k33, k34, k35,   k36,   k37, k38, k39, k3a, k3b }  \
}
#define LAYOUT_atreus44_wrapper(...) LAYOUT_atreus44(__VA_ARGS__)

// Gaming mod-taps and the NAV gaming toggle, as this board has always had
// them (the userspace dropped them for the Scylla).
#define GAME_A LSFT_T(KC_A)
#define GAME_Z LCTL_T(KC_Z)
#define ________________GAMING_L2_________________     GAME_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________GAMING_L3_________________     GAME_Z,    KC_X,    KC_C,    KC_V,    KC_B
#undef ________________NAV_L3________________
#define ________________NAV_L3________________      _______, _______,TG(_GAMING), _______, UNIWL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_atreus44_wrapper(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________MAIN_L2________________,                                ________________MAIN_R2________________,
    ________________MAIN_L3________________,    KC_CAPS,       KC_DEL,      ________________MAIN_R3________________,
    TG(_GAMING), UNIWL,  MO(_SYM), KC_TAB, CACCCV,     UNDO,    REDO,       KC_ENT, KC_SPC, MO(_NUM), NXTPRV, KC_MPLY
  ),

  [_GAMING] = LAYOUT_atreus44_wrapper(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________GAMING_L2_________________,                             ________________MAIN_R2________________,
    ________________GAMING_L3_________________,    KC_CAPS,       KC_DEL,   ________________MAIN_R3________________,
    _______, _______,LT(_SYM, KC_ESC), KC_SPC, KC_TAB,     UNDO,    REDO,       KC_ENT, KC_SPC, MO(_NUM), NXTPRV, KC_MPLY
  ),

  [_SYM] = LAYOUT_atreus44_wrapper(
    ________________SYM_L1________________,                                ________________SYM_R1________________,
    ________________SYM_L2________________,                                ________________SYM_R2________________,
    ________________SYM_L3________________,    KC_CAPS,       KC_DEL,      ________________SYM_R3________________,
    _______, _______, _______, _______, _______, _______, _______,  KC_SPC, _______,MO(_NAV), _______, _______
  ),

  [_ACC] = LAYOUT_atreus44_wrapper(
    ________________ACC_L1________________,                                ________________ACC_R1________________,
    ________________ACC_L2________________,                                ________________ACC_R2________________,
    ________________ACC_L3________________,     _______,  _______,         ________________ACC_R3________________,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT_atreus44_wrapper(
    ________________NUM_L1________________,                                ________________NUM_R1________________,
    ________________NUM_L2________________,                                ________________NUM_R2________________,
    ________________NUM_L3________________,     _______,  _______,         ________________NUM_R3________________,
    _______, _______,MO(_NAV), _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_atreus44_wrapper(
    ________________NAV_L1________________,                                ________________NAV_R1________________,
    ________________NAV_L2________________,                                ________________NAV_R2________________,
    ________________NAV_L3________________,     _______,  _______,         ________________NAV_R3________________,
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

  [_MISC] = LAYOUT_atreus44_wrapper(
    ________________MISC_L1________________,                                ________________MISC_R1________________,
    ________________MISC_L2________________,                                ________________MISC_R2________________,
    ________________MISC_L3________________,     _______,  _______,         ________________MISC_R3________________,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

__attribute__ ((weak))
void matrix_init_keymap(void) {}
void matrix_init_user(void) {
// Atreus 44 is more often on WIN so start in WIN mode
  set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);

  matrix_init_keymap();
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
      tap_code16(KC_VOLU);
  } else {
      tap_code16(KC_VOLD);
  }
  return false;
}
#endif
