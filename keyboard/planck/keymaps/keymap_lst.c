// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _LW 1
#define _RS 2
#define _SP 3
#define _NM 4
#define _MI 5

// For readability
#define __      KC_TRNS
#define ___X___ KC_NO

// TODO: Remove extra reset keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {F(0),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {F(1),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F(2)   },
    {KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_RGUI, KC_RALT, RESET,   BL_INC }
},
[_LW] = { /* LOWER */
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELT},
    {__,      ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_EQL,  KC_ENT },
    {KC_LSFT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LBRC, KC_RBRC, KC_MINS, KC_RSFT},
    {TG(_NM), __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      RESET  }
},
[_RS] = { /* RAISE */
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, KC_DELT},
    {__,      ___X___, ___X___, ___X___, ___X___, ___X___, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PLUS, KC_ENT },
    {KC_LSFT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LCBR, KC_RCBR, KC_UNDS, KC_RSFT},
    {RESET,   __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      TG(_MI)}
},
[_SP] = { /* SPECIAL */
    {__,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __     },
    {__,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      RESET  },
    {__,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __     },
    {__,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __     }
},
[_NM] = { /* NUMPAD */
    {__,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   ___X___, ___X___, KC_PMNS, KC_P7,   KC_P8,   KC_P9,   RESET  },
    {__,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   ___X___, ___X___, KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PENT},
    {__,      KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PEQL},
    {__,      __,      __,      __,      __,      __,      __,      KC_PAST, KC_P0,   KC_PDOT, KC_0,    KC_NLCK}
},
[_MI] = { /* MIDI */
    { MIDI12 },
    { MIDI12 },
    { MIDI12 },
    {RESET,   KC_MPRV, KC_MPLY, KC_MNXT, __,      __,      __,      __,      KC_MUTE, KC_VOLD, KC_VOLU, __}
}
};

const uint16_t PROGMEM fn_actions[] = {
    // Special layer on hold, escape on tap
    [0] = LT(_SP, KC_ESC)

    // Shift modifier on hold, paren on tap
    [1] = SFT_T(KC_LPRN),
    [2] = MT(KC_RSFT, KC_RPRN)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    // On keydown
    if (record->event.pressed) {
        switch(id) {
            case 0:
                break;
        }
    }
    return MACRO_NONE;
};
