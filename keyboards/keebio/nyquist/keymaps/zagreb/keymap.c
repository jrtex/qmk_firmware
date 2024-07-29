// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _LOWER,
    _NAVI,
    _RAISE,
    _ADJUST,
    _WM1
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  NAVI,
  RAISE,
  ADJUST,
  WM1,
};

// homerow mods & special key
#define GUI_Z LGUI_T(KC_Z)
#define ALT_X LALT_T(KC_X)
#define CTL_C LCTL_T(KC_C)
#define SFT_D LSFT_T(KC_D)
#define SFT_H RSFT_T(KC_H)
#define CTL_COM RCTL_T(KC_COMM)
#define ALT_DOT RALT_T(KC_DOT)
#define GUI_SLS RGUI_T(KC_SLSH)

#define NUM_TAB LT(1, KC_TAB)
#define NAV_SPC LT(2, KC_SPC)
#define SFT_FUN LT(3, OSM(MOD_LSFT))
#define ENT_WM1 LT(_WM1 , KC_ENT)
#define W_PRE C(KC_LEFT)
#define W_NXT C(KC_RGHT)

// Combos
const uint16_t PROGMEM combo_dash[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo_coln[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM combo_squo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_dquo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_undr[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM combo_equa[] = {KC_N, KC_E, KC_I, COMBO_END};

const uint16_t PROGMEM combo_excl[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_qust[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_semi[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_tild[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_bquo[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {KC_L, KC_U, KC_Y, COMBO_END};

const uint16_t PROGMEM combo_lsqb[] = {SFT_H, KC_E, COMBO_END};
const uint16_t PROGMEM combo_rsqb[] = {KC_E, ALT_DOT, COMBO_END};
const uint16_t PROGMEM combo_lcrb[] = {KC_N, KC_U, COMBO_END};
const uint16_t PROGMEM combo_rcrb[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_M, KC_J, COMBO_END};

// Left hand
const uint16_t PROGMEM combo_clos[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_escp[] = {KC_W, KC_F, COMBO_END};

const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_past[] = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM combo_cut[]  = {KC_N, KC_E, COMBO_END};

const uint16_t PROGMEM combo_all[]  = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_delw[] = {KC_R, KC_S, KC_T, COMBO_END};

// Combos Definitions
combo_t key_combos[] = {
    COMBO(combo_dash, KC_MINS),
    COMBO(combo_coln, KC_COLN),
    COMBO(combo_squo, KC_QUOT),
    COMBO(combo_dquo, KC_DQT),
    COMBO(combo_undr, KC_UNDS),
    COMBO(combo_equa, KC_EQL),

    COMBO(combo_excl, KC_EXLM),
    COMBO(combo_qust, KC_QUES),
    COMBO(combo_semi, KC_SCLN),
    COMBO(combo_tild, KC_TILD),
    COMBO(combo_bquo, KC_GRV),
    COMBO(combo_plus, KC_PLUS),

    COMBO(combo_lsqb, KC_LBRC),
    COMBO(combo_rsqb, KC_RBRC),
    COMBO(combo_lcrb, KC_LCBR),
    COMBO(combo_rcrb, KC_RCBR),
    COMBO(combo_pipe, KC_PIPE),

    COMBO(combo_clos, LCTL(KC_W)),
    COMBO(combo_escp, KC_ESC),

    COMBO(combo_copy, LCTL(KC_C)),
    COMBO(combo_past, LCTL(KC_V)),
    COMBO(combo_all,  LCTL(KC_A)),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_del,  KC_DEL),
    COMBO(combo_delw, LCTL(KC_BSPC)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_5x12(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, GUI_Z,   ALT_X,   CTL_C,   SFT_D,   KC_V,    KC_K,    SFT_H,   CTL_COM, ALT_DOT, GUI_SLS, KC_RSFT,
  ADJUST,  KC_LGUI, KC_LALT, KC_LCTL, NUM_TAB, NAV_SPC, ENT_WM1, SFT_FUN, KC_RCTL, KC_RALT, KC_RGUI, KC_RGHT
),

[_LOWER] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
  BL_STEP, _______, _______, _______, KC_5,    KC_PERC, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NAVI] =  LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, W_PRE,   KC_UP,   W_NXT,   _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSLS,
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] =  LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, KC_VOLD, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_WM1] = LAYOUT_ortho_5x12(
  LGUI(KC_ESC),  LGUI(KC_1),    LGUI(KC_2),    LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),    LGUI(KC_9),    LGUI(KC_0),    LGUI(KC_BSPC),
  LGUI(KC_TAB),  LGUI(KC_Q),    LGUI(KC_W),    LGUI(KC_F),    LGUI(KC_P),    LGUI(KC_B),    LGUI(KC_J),    LGUI(KC_L),    LGUI(KC_U),    LGUI(KC_Y),    LGUI(KC_SCLN), LGUI(KC_DEL),
  KC_LSFT,       LGUI(KC_A),    LGUI(KC_R),    LGUI(KC_S),    LGUI(KC_T),    LGUI(KC_G),    LGUI(KC_M),    LGUI(KC_N),    LGUI(KC_E),    LGUI(KC_I),    LGUI(KC_O),    LGUI(KC_QUOT),
  LGUI(KC_LSFT), LGUI(KC_Z),    LGUI(KC_X),    LGUI(KC_C),    LGUI(KC_D),    LGUI(KC_V),    LGUI(KC_K),    LGUI(KC_H),    LGUI(KC_COMM), LGUI(KC_DOT),  LGUI(KC_SLSH), LGUI(KC_RSFT),
  _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),

};

#ifdef AUDIO_ENABLE
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_LOWER] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_RAISE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_ADJUST] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COLEMAK:
            rgblight_sethsv(HSV_YELLOW);
            break;
        case _LOWER:
            rgblight_sethsv(HSV_RED);
            break;
        case _NAVI:
            rgblight_sethsv(HSV_BLUE);
            break;
        case _RAISE:
            rgblight_sethsv(HSV_PINK);
            break;
        case _ADJUST:
            rgblight_sethsv(HSV_PURPLE);
            break;
        case _WM1:
            rgblight_sethsv(HSV_ORANGE);
            break;
        default:
            rgblight_sethsv(HSV_CYAN);
            break;
        }
    return state;
}

