#include "keymap_common.h"
#include "planck.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

#define _QW 0 // Qwerty
#define _LW 1 // Lower

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MIT Layout (QWERTY layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃ tab ┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  Y  ┃  U  ┃  I  ┃  O  ┃  P  ┃bkspc┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ esc ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┃  H  ┃  J  ┃  K  ┃  L  ┃  ;  ┃  '  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ Fn0 ┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃  N  ┃  M  ┃  ,  ┃  .  ┃  /  ┃ ent ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃bcklt┃ ctl ┃ alt ┃ cmd ┃ Fn1 ┃   space   ┃reset┃ left┃ down┃  up ┃right┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_QW] = { /* QWERTY */
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {F(0),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, F(1),    KC_SPC,  KC_SPC,  RESET,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_LW] = { /* LOWER */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
}
};

const uint16_t PROGMEM fn_actions[] = {
    // Equivalent to ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LPRN)
    [0] = ACTION_MACRO_TAP(0),

    // Equivalent to ACTION_LAYER_TAP_KEY(_LW, KC_LPRN)
    [1] = ACTION_MACRO_TAP(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 0: // ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LPRN)
            if (record->event.pressed) {
                // Activate shift
                register_mods(MOD_LSFT);
                record->tap.interrupted = 0;
            } else {
                // If the action was a tap
                if (record->tap.count && !record->tap.interrupted) {
                    // Send 9, which is modified by shift as per above
                    register_code(KC_9);
                    unregister_code(KC_9);
                }
                // Deactivate shift
                unregister_mods(MOD_LSFT);
                record->tap.count = 0;
            }
            break;
        case 1: // ACTION_LAYER_TAP_KEY(_LW, KC_LPRN)
            if (record->event.pressed) {
                // Turn desired layer on
                layer_on(_LW);
                record->tap.interrupted = 0;
            } else {
                // If the action was a tap
                if (record->tap.count && !record->tap.interrupted) {
                    // Send a left paren via shift + 9
                    add_weak_mods(MOD_LSFT); // Doesn't affect actual shift status
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_LSFT);
                }
                // Deactivate layer
                layer_off(_LW);
                record->tap.count = 0;
            }
            break;
    }
    return MACRO_NONE;
};
