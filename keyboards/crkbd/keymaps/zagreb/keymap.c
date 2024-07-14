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


// homerow mods
#define GUI_Z LGUI_T(KC_Z)
#define ALT_X LALT_T(KC_X)
#define CTRL_C LCTL_T(KC_C)
#define SHFT_D LSFT_T(KC_D)
#define SHFT_H RSFT_T(KC_H)
#define CTRL_CM RALT_T(KC_COMM)
#define ALT_DOT RCTL_T(KC_DOT)
#define GUI_SLS RGUI_T(KC_SLSH)
#define SHFTFUN LT(3, OSM(MOD_LSFT))

// Combos Config:
// Right hand
const uint16_t PROGMEM combo_dash[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo_coln[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM combo_squo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_dquo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_undr[] = {KC_M, KC_E, COMBO_END};

const uint16_t PROGMEM combo_excl[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_qust[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_semi[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_tild[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM combo_lsqb[] = {KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM combo_rsqb[] = {KC_E, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_lcrb[] = {KC_N, KC_U, COMBO_END};
const uint16_t PROGMEM combo_rcrb[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_J, KC_M, COMBO_END};

// Left Hand
const uint16_t PROGMEM combo_escp[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_past[] = {KC_C, KC_D, COMBO_END};

// Combos Definition:
combo_t key_combos[] = {
    // right hand
    COMBO(combo_dash, KC_MINS),
    COMBO(combo_coln, KC_COLN),
    COMBO(combo_squo, KC_QUOT),
    COMBO(combo_dquo, KC_DQT),

    COMBO(combo_excl, KC_EXLM),
    COMBO(combo_qust, KC_QUES),
    COMBO(combo_semi, KC_SCLN),
    COMBO(combo_tild, KC_TILD),

    COMBO(combo_lsqb, KC_LBRC),
    COMBO(combo_rsqb, KC_RBRC),
    COMBO(combo_lcrb, KC_LCBR),
    COMBO(combo_rcrb, KC_RCBR),
    COMBO(combo_pipe, KC_PIPE),

    // left hand
    COMBO(combo_escp, KC_ESC),
    COMBO(combo_copy, LCTL(KC_C)),
    COMBO(combo_past, LCTL(KC_V)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    GUI_Z,   ALT_X,   CTRL_C,  SHFT_D,  KC_V,                         KC_K,    SHFT_H,  CTRL_CM, ALT_DOT, GUI_SLS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI, LT(1, KC_TAB), LT(2, KC_SPC),    KC_ENT,  SHFTFUN, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      KC_MINS,  KC_DEL,  KC_END, KC_PGDN, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
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

    [4] = LAYOUT_split_3x6_3(
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
};
