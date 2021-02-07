#pragma once

#define NO_ACTION_MACRO
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD

// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

#define COMBO_VARIABLE_LEN
#define COMBO_COUNT COMBO_VARIABLE_LEN
#define COMBO_TERM 70

#define UNICODE_SELECTED_MODES UC_LNX, UC_WINC

// Mouse Keys
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 50
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 20

/* #define UNICODE_KEY_LNX LCTL(LSFT(KC_E)) */
