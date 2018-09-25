#include "planck.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif
// #ifdef MIDI_ENABLE
//   #include "keymap_midi.h"
//   #include "audio.h"
// #endif

#define _QW 0 // Qwerty
#define _GM 1 // Gaming
#define _LW 2 // Lower
#define _RS 3 // Upper
#define _FN 4 // Functions
#define _MD 5 // Media
#define _NU 6 // Numpad
#define _MI 7 // Midi

// For readability
#define __      KC_TRNS
#define ___X___ KC_NO
#define KC_PWR  KC_POWER
#define HYPER M(8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MIT Layout (QWERTY layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃ tab ┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  Y  ┃  U  ┃  I  ┃  O  ┃  P  ┃bkspc┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ fn0 ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┃  H  ┃  J  ┃  K  ┃  L  ┃  ;  ┃  '  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ fn6 ┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃  N  ┃  M  ┃  ,  ┃  .  ┃  /  ┃ fn7 ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ fn5 ┃hyper┃ alt ┃ cmd ┃ fn2 ┃   space   ┃ fn3 ┃ cmd ┃ alt ┃ meh ┃ fn4 ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_QW] = { /* QWERTY */
	{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
	{F(0),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
	{F(6),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F(7)   },
	{F(_MD),  HYPER,   KC_LALT, KC_LGUI, F(_LW),  KC_SPC,  KC_SPC,  F(_RS),  KC_RGUI, KC_RALT, HYPER,   F(_FN) }
},
/* MIT Layout (GAMING layer)
 * Disables tap-key actions in favor of low latency
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃ tab ┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  Y  ┃  U  ┃  I  ┃  O  ┃  P  ┃bkspc┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ esc ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┃  H  ┃  J  ┃  K  ┃  L  ┃  ;  ┃  '  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃shift┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃  N  ┃  M  ┃  ,  ┃  .  ┃  /  ┃ fn7 ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ ctl ┃funcs┃ alt ┃ alt ┃lower┃   space   ┃raise┃ cmd ┃ alt ┃ ctl ┃ fn4 ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_GM] = { /* GAMING */
	{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
	{KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
	{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F(7)   },
	{KC_LCTL, MO(_FN), KC_LALT, KC_LALT, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_RGUI, KC_RALT, KC_RCTL, F(_FN) }
},
/* MIT Layout (LOWERED layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃  `  ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃  6  ┃  7  ┃  8  ┃  9  ┃  0  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃ left┃ down┃  up ┃right┃  [  ┃  ]  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  \  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_LW] = { /* LOWER */
	{KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __     },
	{__,      ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC},
	{__,      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_BSLS, __     },
	{TG(_NU), __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      RESET  }
},
/* MIT Layout (RAISED layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃  ~  ┃  !  ┃  @  ┃  #  ┃  $  ┃  %  ┃  ^  ┃  &  ┃  *  ┃  -  ┃  =  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃ left┃ down┃  up ┃right┃  {  ┃  }  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  |  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_RS] = { /* RAISE */
	{KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  __     },
	{__,      ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LCBR, KC_RCBR},
	{__,      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_PIPE, __     },
	{TG(_GM), __,      __,      __,      __,      __,      __,      __,      __,      __,      __,      TG(_NU)}
},
/* MIT Layout (FUNCTION layer)
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
/* MIT Layout (MEDIA layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃ ms1 ┃ msup┃ ms2 ┃     ┃ pwr ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃brtsc┃bkltu┃volup┃     ┃     ┃     ┃ mslf┃ msdn┃ msrt┃     ┃sleep┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃dimsc┃bkltd┃voldn┃     ┃     ┃     ┃ ms3 ┃ mwup┃ ms4 ┃     ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃mprev┃mplay┃mnext┃ mute┃           ┃ mwlf┃ mwdn┃ mwrt┃     ┃     ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_MD] = { /* MEDIA */
	{__,      __,      __,      __,      __,      __,      __,      KC_BTN1, KC_MS_U, KC_BTN2, __,      KC_PWR },
	{__,      KC_PAUS, BL_INC,  KC_VOLU, __,      __,      __,      KC_MS_L, KC_MS_D, KC_MS_R, __,      KC_SLEP},
	{__,      KC_SLCK, BL_DEC,  KC_VOLD, __,      __,      __,      KC_BTN3, KC_WH_U, KC_BTN4, __,      __     },
	{__,      KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, __,      __,      KC_WH_L, KC_WH_D, KC_WH_R, __,      __     }
},
/* MIT Layout (NUMPAD REFLECTED layer)
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
[_NU] = { /* NUMPAD */
	{__,      KC_TAB,  KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, KC_NLCK, __,      __,      __,      __     },
	{__,      KC_TAB,  KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, __,      __,      __,      __,      __     },
	{__,      __,      KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, __,      __,      __,      __,      __     },
	{__,      __,      KC_PENT, KC_PDOT, KC_PCMM, KC_P0,   KC_P0,   __,      __,      __,      __,      __     }
},
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
// [_MI] = { /* MIDI */
// 	{ MIDI12 },
// 	{ MIDI12 },
// 	{ MIDI12 },
// 	{__,   KC_MPRV, KC_MPLY, KC_MNXT, __,      __,      __,      __,      KC_MUTE, KC_VOLD, KC_VOLU, M(0)}
// }
};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),

	[_LW] = ACTION_MACRO_TAP(_LW),
	[_RS] = ACTION_MACRO_TAP(_RS),
	[_FN] = ACTION_MACRO_TAP(_FN),
	// [_MD] = ACTION_LAYER_TAP_TOGGLE(_MD),
	[_MD] = ACTION_LAYER_MOMENTARY(_MD),

	[6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),
	[7] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch(id) {
		case _LW:
			if (record->event.pressed) {
				layer_on(_LW);
			} else {
				if (record->tap.count && !record->tap.interrupted) {
					add_weak_mods(MOD_LSFT);
					register_code(KC_9);
					unregister_code(KC_9);
					del_weak_mods(MOD_LSFT);
				}
				layer_off(_LW);
				record->tap.count = 0;
			}
			break;
		case _RS:
			if (record->event.pressed) {
				layer_on(_RS);
			} else {
				if (record->tap.count && !record->tap.interrupted) {
					add_weak_mods(MOD_LSFT);
					register_code(KC_0);
					unregister_code(KC_0);
					del_weak_mods(MOD_LSFT);
				}
				layer_off(_RS);
			}
			break;
		case _FN:
			if (record->event.pressed) {
				layer_on(_FN);
			} else {
				if (record->tap.count && !record->tap.interrupted) {
					#ifdef BACKLIGHT_ENABLE
						backlight_step();
					#endif
				}
				layer_off(_FN);
				record->tap.count = 0;
			}
			break;
		case 8:
			if (record->event.pressed) {
				register_code(KC_LCTL);
				register_code(KC_LALT);
				register_code(KC_LSFT);
				register_code(KC_LGUI);
			} else {
				unregister_code(KC_LCTL);
				unregister_code(KC_LALT);
				unregister_code(KC_LSFT);
				unregister_code(KC_LGUI);
			}
	}
	// MACRODOWN only works in this function
	return MACRO_NONE;
};
