// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _NUM,
    _NAVI,
    _FUN,
    _MEDIA,
    _WM1,
    _WM2
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  NUM,
  NAVI,
  FUN,
  MEDIA,
  WM1,
  WM2,
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
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, GUI_Z,   ALT_X,   CTL_C,   SFT_D,   KC_V,    KC_K,    SFT_H,   CTL_COM, ALT_DOT, GUI_SLS, KC_RSFT,
  MEDIA,  KC_LGUI, KC_LALT, KC_LCTL, NUM_TAB, NAV_SPC, ENT_WM1, SFT_FUN, KC_RCTL, KC_RALT, KC_RGUI, KC_RGHT
),

[_NUM] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
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

[_FUN] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSLS,
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] =  LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, KC_VOLD, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_WM1] = LAYOUT_ortho_5x12(
  G(KC_ESC),  G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5),    G(KC_6),    G(KC_7),    G(KC_8),    G(KC_9),    G(KC_0),    G(KC_BSPC),
  G(KC_TAB),  G(KC_Q),    G(KC_W),    G(KC_F),    G(KC_P),    G(KC_B),    G(KC_J),    G(KC_L),    G(KC_U),    G(KC_Y),    G(KC_SCLN), G(KC_DEL),
  KC_LSFT,    G(KC_A),    G(KC_R),    G(KC_S),    G(KC_T),    G(KC_G),    G(KC_M),    G(KC_N),    G(KC_E),    G(KC_I),    G(KC_O),    G(KC_QUOT),
  G(KC_LSFT), G(KC_Z),    G(KC_X),    G(KC_C),    G(KC_D),    G(KC_V),    G(KC_K),    G(KC_H),    G(KC_COMM), G(KC_DOT),  G(KC_SLSH), G(KC_RSFT),
  _______,  _______, _______, _______, _______,  MO(_WM2), _______,  _______, _______, _______, _______, _______
),

[_WM2] = LAYOUT_ortho_5x12(
  S(G(KC_ESC)),  S(G(KC_1)),    S(G(KC_2)),    S(G(KC_3)),    S(G(KC_4)),    S(G(KC_5)),    S(G(KC_6)),    S(G(KC_7)),    S(G(KC_8)),    S(G(KC_9)),    S(G(KC_0)),    S(G(KC_BSPC)),
  S(G(KC_TAB)),  S(G(KC_Q)),    S(G(KC_W)),    S(G(KC_F)),    S(G(KC_P)),    S(G(KC_B)),    S(G(KC_J)),    S(G(KC_L)),    S(G(KC_U)),    S(G(KC_Y)),    S(G(KC_SCLN)), S(G(KC_DEL)),
  KC_LSFT,    S(G(KC_A)),    S(G(KC_R)),    S(G(KC_S)),    S(G(KC_T)),    S(G(KC_G)),    S(G(KC_M)),    S(G(KC_N)),    S(G(KC_E)),    S(G(KC_I)),    S(G(KC_O)),    S(G(KC_QUOT)),
  S(G(KC_LSFT)), S(G(KC_Z)),    S(G(KC_X)),    S(G(KC_C)),    S(G(KC_D)),    S(G(KC_V)),    S(G(KC_K)),    S(G(KC_H)),    S(G(KC_COMM)), S(G(KC_DOT)),  S(G(KC_SLSH)), S(G(KC_RSFT)),
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
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
        update_tri_layer(_NUM, _FUN, _MEDIA);
      } else {
        layer_off(_NUM);
        update_tri_layer(_NUM, _FUN, _MEDIA);
      }
      return false;
      break;
    case FUN:
      if (record->event.pressed) {
        layer_on(_FUN);
        update_tri_layer(_NUM, _FUN, _MEDIA);
      } else {
        layer_off(_FUN);
        update_tri_layer(_NUM, _FUN, _MEDIA);
      }
      return false;
      break;
    case MEDIA:
      if (record->event.pressed) {
        layer_on(_MEDIA);
      } else {
        layer_off(_MEDIA);
      }
      return false;
      break;
  }
  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_NUM] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_FUN] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_MEDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COLEMAK:
            rgblight_sethsv(HSV_YELLOW);
            break;
        case _NUM:
            rgblight_sethsv(HSV_RED);
            break;
        case _NAVI:
            rgblight_sethsv(HSV_BLUE);
            break;
        case _FUN:
            rgblight_sethsv(HSV_PINK);
            break;
        case _MEDIA:
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

