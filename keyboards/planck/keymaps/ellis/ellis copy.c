#include "keymap_common.h"
#include "planck.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

#define _QW 0 // Qwerty
#define _LW 1 // Lower
#define _RS 2 // Upper
#define _FN 3 // Functions
#define _NU 4 // Numpad
#define _MI 5 // Midi

// For readability
#define __      KC_TRNS
#define ___X___ KC_NO

// TODO: Remove extra reset keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MIT Layout (QWERTY layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃ tab ┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  Y  ┃  U  ┃  I  ┃  O  ┃  P  ┃bkspc┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ esc ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┃  H  ┃  J  ┃  K  ┃  L  ┃  ;  ┃  '  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ fn2 ┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃  N  ┃  M  ┃  ,  ┃  .  ┃  /  ┃ fn3 ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ fn0 ┃ ctl ┃ alt ┃ cmd ┃lower┃   space   ┃raise┃ cmd ┃ alt ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_QW] = { /* QWERTY */
	{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
	{F(1),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
	{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
	{BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_RGUI, KC_RALT, KC_RCTL, LT(0)  }
},
/* MIT Layout (LOWERED layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃  `  ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃  6  ┃  7  ┃  8  ┃  9  ┃  0  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃ left┃ down┃  up ┃right┃  [  ┃enter┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃shift┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃  ]  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_LW] = { /* LOWER */
	{KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __     },
	{__,      ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_EQL,  KC_ENT },
	{KC_LSFT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LBRC, KC_RBRC, KC_MINS, __     },
	{TG(_NU), __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      RESET  }
},
/* MIT Layout (RAISED layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃  ~  ┃  !  ┃  @  ┃  #  ┃  $  ┃  %  ┃  ^  ┃  &  ┃  *  ┃  -  ┃  =  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃ left┃ down┃  up ┃right┃  \  ┃enter┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃shift┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_RS] = { /* RAISE */
	{KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, __     },
	{__,      ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS, KC_ENT },
	{KC_LSFT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LCBR, KC_RCBR, KC_UNDS, __     },
	{RESET,   __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      __     }
},
/* MIT Layout (FN layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃     ┃ F1  ┃ F2  ┃ F3  ┃ F4  ┃ F5  ┃ F6  ┃     ┃ ins ┃ home┃ pgup┃ del ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃ F7  ┃ F8  ┃ F9  ┃ F10 ┃ F11 ┃ F12 ┃     ┃ del ┃ end ┃ pgdn┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃  up ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃           ┃     ┃ left┃ down┃right┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_FN] = { /* FUNCTIONS */
	{__,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   __,      KC_INS,  KC_HOME, KC_PGUP, KC_DELT},
	{__,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  __,      KC_DELT, KC_END,  KC_PGDN, __     },
	{__,      __,      __,      __,      __,      __,      __,      __,      __,      KC_UP,   __,      __     },
	{__,      __,      __,      __,      __,      __,      __,      __,      KC_LEFT, KC_DOWN, KC_RGHT, __     }
},
/* MIT Layout (NUMPAD layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃     ┃numlk┃  -  ┃  9  ┃  8  ┃  7  ┃bkspc┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃  +  ┃  6  ┃  5  ┃  4  ┃  *  ┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃enter┃  3  ┃  2  ┃  1  ┃  /  ┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃enter┃  .  ┃  ,  ┃     0     ┃     ┃     ┃     ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_NU] = { /* NUMPAD REFLECTED */
	{__,      KC_NLCK, KC_PMNS, KC_P9,   KC_P8,   KC_P7,   KC_BSPC, __,      __,      __,      __,      __     },
	{__,      __,      KC_PPLS, KC_P6,   KC_P5,   KC_P4,   KC_PAST, __,      __,      __,      __,      __     },
	{__,      __,      KC_PENT, KC_P3,   KC_P2,   KC_P1,   KC_PSLS, __,      __,      __,      __,      __     },
	{__,      __,      KC_PENT, KC_PDOT, KC_PCMM, KC_P0,   KC_P0,   __,      __,      __,      __,      __     }
}, /*
[_NM] = { // NUMPAD
	{__,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   ___X___, ___X___, KC_PMNS, KC_P7,   KC_P8,   KC_P9,   RESET  },
	{__,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   ___X___, ___X___, KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PENT},
	{__,      KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PEQL},
	{__,      __,      __,      __,      __,      __,      __,      KC_PAST, KC_P0,   KC_PDOT, KC_P0,   KC_NLCK}
}, */
/* MIT Layout (MIDI layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
//[_MI] = { /* MIDI */
//    { MIDI12 },
//    { MIDI12 },
//    { MIDI12 },
//    {RESET,   KC_MPRV, KC_MPLY, KC_MNXT, __,      __,      __,      __,      KC_MUTE, KC_VOLD, KC_VOLU, __}
//}
};

const uint16_t PROGMEM fn_actions[] = {
	// Function layer on hold, caps lock on tap
//	[0] = ACTION_LAYER_TAP_KEY(_FN, KC_CAPS),
	[1] = ACTION_MODS_TAP_KEY(KC_LCTL, KC_ESC)

	// Shift modifier on hold, paren on tap
	[2] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LPRN),
	[3] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_RPRN)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
// MACRODOWN only works in this function
//	switch(id) {
//		case 0:
//			if (record->event.pressed) {
//				#ifdef BACKLIGHT_ENABLE
//					backlight_step();
//				#endif
//			}
//		break;
//	}
	return MACRO_NONE;
};
