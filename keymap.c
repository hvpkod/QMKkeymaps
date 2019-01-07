/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

// Tap Dance Declarations
enum
{
  TD1 = 0,
  TD2,
  TD3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ALTTAB | A      | S      | D      | F      | G      | HOME   |  UP    | END    | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------t+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PG ND  | DOWN   | PG UP  | N      | M      | ,      | .      | /      | MODT   |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | FN     | LALT   | BACKSP | SPACE  | LCTRL  | DEL    | MO     | RALT   | ENTER  | LEFT   | DOWN   |  UP    |  RIGHT |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_QW] = {
        /* QWERTY */
        {KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC},
        {KC_TAB, TD(TD1), KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, TD(TD3), KC_P, KC_QUOT},
        {LALT(KC_TAB), TD(TD2), KC_S, KC_D, KC_F, KC_G, KC_HOME, KC_UP, KC_END, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT},
        {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_PGDN, KC_DOWN, KC_PGUP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TG(_FN)},
        {KC_LCTL, KC_LGUI, MO(_FN), KC_LALT, KC_BSPC, KC_SPC, KC_LCTL, SFT_T(KC_DEL), KC_RALT, MO(_FN), KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT},
    },

    // [_QW] = {
    //     /* QWERTY */
    //     {KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC},
    //     {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT},
    //     {TG(_FN), KC_A, KC_S, KC_D, KC_F, KC_G, KC_HOME, KC_DEL, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT},
    //     {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END, KC_UP, KC_PGDN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT},
    //     {KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_ENT, MO(_FN), KC_RALT, KC_RGUI, KC_RCTL},
    // },

    /* FUNCTION 
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |   F6   |        | F7     | F8     | F9     | F10    | F11    | F12    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   å    |        |        |        |        | P7     | P8     | P9     | -      |  P/    |        |  ö     | PR SCR | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   ä    |        |        |        |        | P4     | P5     | P6     | +      |    P*  |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | P1     | P2     | P3     | PENT   | PLAY   | NEXT   | VOL-   | VOL+   | MODT   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | FN     |        |        |        | P0     |        | P.     |        | PENT   |  HOME  | PG DN  | PG UP  |  END   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_FN] = {
        /* FUNCTION */
        {KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL},
        {_______, RALT(KC_W), _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_MINS, _______, _______, RALT(KC_O), KC_PSCR, RESET},
        {_______, RALT(KC_A), _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PLUS, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PENT, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, TG(_FN)},
        {KC_LCTL, _______, MO(_FN), _______, KC_DEL, _______, KC_P0, KC_PDOT, _______, MO(_FN), KC_PENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END},
    }};

//[_FN] = {
//    /* FUNCTION */
//    {TG(_FN), _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PLUS, _______, _______, _______, _______, _______},
//    {KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PENT, _______, _______, _______, _______, _______},
//    {_______, _______, _______, MO(_FN), _______, _______, KC_P0, _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, RESET},

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
  {
  case 0:
    if (record->event.pressed)
    {
      register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
      backlight_step();
#endif
    }
    else
    {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

// Tap dance 1
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    register_code(KC_RALT);
    register_code(KC_W);
  }
  else
  {
    register_code(KC_Q);
  }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    unregister_code(KC_RALT);
    unregister_code(KC_W);
  }
  else
  {
    unregister_code(KC_Q);
  }
}

// Tap dance 2
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    register_code(KC_RALT);
    register_code(KC_A);
  }
  else
  {
    register_code(KC_A);
  }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    unregister_code(KC_RALT);
    unregister_code(KC_A);
  }
  else
  {
    unregister_code(KC_A);
  }
}

// Tap dance 3
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    register_code(KC_RALT);
    register_code(KC_O);
  }
  else
  {
    register_code(KC_O);
  }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    unregister_code(KC_RALT);
    unregister_code(KC_O);
  }
  else
  {
    unregister_code(KC_O);
  }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // simple tap dance
    [TD1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),

    [TD2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),

    [TD3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset)};