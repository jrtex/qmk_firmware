/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _NUM,
    _FUN,
    _NAV,
    _MED,
    _KOM,
    _KOM2
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    NUM,
    FUN,
    NAV,
    MED,
    KOM,
    KOM2,
};

// homerow mods
#define GUI_Z LGUI_T(KC_Z)
#define ALT_X LALT_T(KC_X)
#define CTRL_C LCTL_T(KC_C)
#define SHFT_D LSFT_T(KC_D)
#define SHFT_H RSFT_T(KC_H)
#define CTRL_CM RCTL_T(KC_COMM)
#define ALT_DOT RALT_T(KC_DOT)
#define GUI_SLS RGUI_T(KC_SLSH)

#define NUM_TAB LT(_NUM, KC_TAB)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SHFTFUN LT(_FUN, OSM(MOD_LSFT))

#define ENT_WM1 LT(_KOM, KC_ENT)


// Combos Config:
// Right hand
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

const uint16_t PROGMEM combo_lsqb[] = {SHFT_H, KC_E, COMBO_END};
const uint16_t PROGMEM combo_rsqb[] = {KC_E, ALT_DOT, COMBO_END};
const uint16_t PROGMEM combo_lcrb[] = {KC_N, KC_U, COMBO_END};
const uint16_t PROGMEM combo_rcrb[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {KC_M, KC_L, COMBO_END};

// Left Hand
const uint16_t PROGMEM combo_clos[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_escp[] = {KC_W, KC_F, COMBO_END};

const uint16_t PROGMEM combo_all[]  = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_delw[] = {KC_R, KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM combo_copy[] = {ALT_X, CTRL_C, COMBO_END};
const uint16_t PROGMEM combo_past[] = {CTRL_C, SHFT_D, COMBO_END};

// Combos Definition:
combo_t key_combos[] = {
    // right hand
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
    COMBO(combo_bsls, KC_BSLS),

    // left hand
    COMBO(combo_clos, LCTL(KC_W)),
    COMBO(combo_escp, KC_ESC),

    COMBO(combo_all,  LCTL(KC_A)),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_del,  KC_DEL),
    COMBO(combo_delw, LCTL(KC_BSPC)),

    COMBO(combo_copy, LCTL(KC_C)),
    COMBO(combo_past, LCTL(KC_V)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    GUI_Z,   ALT_X,   CTRL_C,  SHFT_D,  KC_V,                         KC_K,    SHFT_H,  CTRL_CM, ALT_DOT, GUI_SLS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, NUM_TAB, NAV_SPC,    ENT_WM1,  SHFTFUN, OSM(MOD_LSFT)
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BSPC, XXXXXXX, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, C(KC_LEFT), KC_UP, C(KC_RGHT), XXXXXXX,                  XXXXXXX,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      KC_MINS,  KC_DEL,  KC_END, KC_PGDN, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(4),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_MED] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_VOLD, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_KOM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, A(KC_Q), A(KC_W), A(KC_F), A(KC_P), A(KC_B),                      A(KC_J), A(KC_L), A(KC_U), A(KC_Y), A(KC_SCLN), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, A(KC_A), A(KC_R), A(KC_S), A(KC_T), A(KC_G),                      A(KC_M), A(KC_N), A(KC_E), A(KC_I), A(KC_O), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, A(KC_Z), A(KC_X), A(KC_C), A(KC_D), A(KC_V),                      A(KC_K), A(KC_H), A(KC_E), A(KC_COMM), A(KC_DOT), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, MO(_KOM2),   _______,  XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_KOM2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, S(A(KC_Q)), S(A(KC_W)), S(A(KC_F)), S(A(KC_P)), S(A(KC_B)),      S(A(KC_J)), S(A(KC_L)), S(A(KC_U)), S(A(KC_Y)), S(A(KC_SCLN)), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(A(KC_A)), S(A(KC_R)), S(A(KC_S)), S(A(KC_T)), S(A(KC_G)),      S(A(KC_M)), S(A(KC_N)), S(A(KC_E)), S(A(KC_I)), S(A(KC_O)), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(A(KC_Z)), S(A(KC_X)), S(A(KC_C)), S(A(KC_D)), S(A(KC_V)),      S(A(KC_K)), S(A(KC_H)), S(A(KC_E)), S(A(KC_COMM)), S(A(KC_DOT)), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, _______,     _______,  XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};
