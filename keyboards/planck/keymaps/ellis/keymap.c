#include "planck.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif
// #ifdef MIDI_ENABLE
//   #include "keymap_midi.h"
//   #include "audio.h"
// #endif

enum planck_layers {
	_QW, // Qwerty
	_GM, // Gaming
	_LW, // Lower
	_RS, // Upper
	_FN, // Functions
	_MD, // Media
	_NU, // Numpad
	_PLOVER, // Plover
};

enum planck_keycodes {
  PLOVER = SAFE_RANGE,
  BACKLIT,
  EXT_PLV,
  LW_T,
  RS_T,
  FN_T,
  HYPER,
};

// For readability
#define ___X___ KC_NO
#define LOWER  LT(_LW, LW_T)
#define RAISE  LT(_RS, RS_T)
#define FUNCT  LT(_FN, FN_T)
#define ESCAPE CTL_T(KC_ESC)
#define LSHIFT SFT_T(KC_CAPS)
#define RSHIFT RSFT_T(KC_ENT)

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
 * ┃ fn5 ┃hyper┃ alt ┃ cmd ┃ fn2 ┃   space   ┃ fn3 ┃ cmd ┃ alt ┃ hyp ┃ fn4 ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_QW] = LAYOUT_planck_grid( /* QWERTY */
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	ESCAPE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	LSHIFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSHIFT ,
	MO(_MD), HYPER,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, HYPER,   FUNCT
),
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
[_GM] = LAYOUT_planck_grid( /* GAMING */
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSHIFT ,
	KC_LCTL, MO(_FN), KC_LALT, KC_LALT, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_RGUI, KC_RALT, KC_RCTL, FUNCT
),
/* MIT Layout (LOWERED layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃  `  ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃  6  ┃  7  ┃  8  ┃  9  ┃  0  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃ left┃ down┃  up ┃right┃  [  ┃  ]  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  \  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃ num ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃ dfu ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_LW] = LAYOUT_planck_grid( /* LOWER */
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
	_______, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_BSLS, _______,
	TG(_NU), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
),
/* MIT Layout (RAISED layer)
 *
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃  ~  ┃  !  ┃  @  ┃  #  ┃  $  ┃  %  ┃  ^  ┃  &  ┃  *  ┃  -  ┃  =  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃ left┃ down┃  up ┃right┃  {  ┃  }  ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃     ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  ╳  ┃  |  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃game ┃     ┃     ┃     ┃     ┃           ┃     ┃     ┃     ┃     ┃ plo ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
[_RS] = LAYOUT_planck_grid( /* RAISE */
	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,
	_______, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LCBR, KC_RCBR,
	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_PIPE, _______,
	TG(_GM), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, PLOVER
),
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
[_FN] = LAYOUT_planck_grid( /* FUNCTIONS */
	_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_INS,  KC_HOME, KC_PGUP, KC_DELT,
	_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DELT, KC_END,  KC_PGDN, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______
),
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
[_MD] = LAYOUT_planck_grid( /* MEDIA */
	_______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_PWR ,
	_______, KC_PAUS, BL_INC,  KC_VOLU, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_SLEP,
	_______, KC_SLCK, BL_DEC,  KC_VOLD, _______, _______, _______, KC_BTN3, KC_WH_U, KC_BTN4, _______, _______,
	_______, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______
),
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
[_NU] = LAYOUT_planck_grid( /* NUMPAD */
	_______, KC_TAB,  KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, KC_NLCK, _______, _______, _______, _______,
	_______, KC_TAB,  KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, _______, _______, _______, _______,
	_______, _______, KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______, _______, _______, _______, _______,
	_______, _______, KC_PENT, KC_PDOT, KC_PCMM, KC_P0,   KC_P0,   _______, _______, _______, _______, _______
),
/* Plover layer (http://opensteno.org)
 * Flipped!
 * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
 * ┃     ┃     ┃     ┃     ┃  U  ┃  E  ┃  O  ┃  A  ┃     ┃     ┃     ┃Exit ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃  Z  ┃  S  ┃  G  ┃  B  ┃  R  ┃  *  ┃  *  ┃  R  ┃  W  ┃  K  ┃  S  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃  D  ┃  T  ┃  L  ┃  P  ┃  F  ┃  *  ┃  *  ┃  H  ┃  P  ┃  T  ┃  S  ┃     ┃
 * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
 * ┃  #  ┃  #  ┃  #  ┃  #  ┃  #  ┃     #     ┃  #  ┃  #  ┃  #  ┃  #  ┃  #  ┃
 * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
 */
// Original:
/* [_PLOVER] = LAYOUT_planck_grid(
 *     KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
 *     ___X___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
 *     ___X___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
 *     EXT_PLV, ___X___, ___X___, KC_C,    KC_V,    ___X___, ___X___, KC_N,    KC_M,    ___X___, ___X___, ___X___
 * ),
 */
// Flipped:
[_PLOVER] = LAYOUT_planck_grid(
    ___X___, ___X___, ___X___, ___X___, KC_M,    KC_N,    KC_V,    KC_C,    ___X___, ___X___, ___X___, EXT_PLV,
    KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    ___X___,
    KC_LBRC, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    ___X___,
    KC_1   , KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1
),
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// uint32_t layer_state_set_user(uint32_t state) {
// 	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case BACKLIT:
			if (record->event.pressed) {
				register_code(KC_RSFT);
				#ifdef BACKLIGHT_ENABLE
					backlight_step();
				#endif
				#ifdef KEYBOARD_planck_rev5
					PORTE &= ~(1<<6);
				#endif
			} else {
				unregister_code(KC_RSFT);
				#ifdef KEYBOARD_planck_rev5
					PORTE |= (1<<6);
				#endif
			}
			return false;
		case PLOVER:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					stop_all_notes();
					PLAY_SONG(plover_song);
				#endif
				layer_off(_RS);
				layer_off(_LW);
				layer_off(_FN);
				layer_on(_PLOVER);
				if (!eeconfig_is_enabled()) {
					eeconfig_init();
				}
				keymap_config.raw = eeconfig_read_keymap();
				keymap_config.nkro = 1;
				eeconfig_update_keymap(keymap_config.raw);
			}
			return false;
		case EXT_PLV:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_SONG(plover_gb_song);
				#endif
				layer_off(_PLOVER);
			}
			return false;
		case LW_T:
			if (record->event.pressed) {
				add_weak_mods(MOD_LSFT);
				register_code(KC_9);
				unregister_code(KC_9);
				del_weak_mods(MOD_LSFT);
			}
			return false;
		case RS_T:
			if (record->event.pressed) {
				add_weak_mods(MOD_LSFT);
				register_code(KC_0);
				unregister_code(KC_0);
				del_weak_mods(MOD_LSFT);
			}
			return false;
		case FN_T:
			if (record->event.pressed) {
				#ifdef BACKLIGHT_ENABLE
					backlight_step();
				#endif
			}
			return false;
		case HYPER:
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
			return false;
	}
	return true;
}
