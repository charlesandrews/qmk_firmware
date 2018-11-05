/* Copyright 2018 Charles Andrews
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

/* This is the default ANSI layout provided by the KBP V60 Type R
* as depicted in their manual and on the stock keycaps.
*/
#include QMK_KEYBOARD_H

enum {
	TD_EASY_BRACKETS_LEFT = 0,
	TD_EASY_BRACKETS_RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Fn0    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space              |Fn0 |Gui |App|Ctrl|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
	       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_EASY_BRACKETS_LEFT), TD(TD_EASY_BRACKETS_RIGHT), KC_BSLS, \
	       MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
	       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,   \
	       KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                                      MO(1),   KC_RGUI, KC_APP,  KC_RCTL),

  /* Keymap 1: FN Layer
   * ,-----------------------------------------------------------.
   * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |Prt|Scl|Pau|Up|   | Ins  |
   * |-----------------------------------------------------------|
   * |      |Lft|Dwn|Rig|   |   |   |   |Hme|PgU|Lef|Rig|        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |VolD|VolU|Mut|End|PgD|Dwn|        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [1] = LAYOUT_60_ansi(
	       KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL, \
	       KC_TRNS,   KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    KC_TRNS,          KC_INS, \
	       KC_TRNS,   KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          KC_TRNS,          \
	       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,   KC_VOLU, KC_MUTE, KC_END,  KC_PGDN,  KC_DOWN,           KC_TRNS,  \
	       KC_TRNS,   KC_TRNS,  KC_TRNS,            KC_TRNS,                                                           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),

};

void dance_brackets_left_finished(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		register_code (KC_LBRC);
	}else if (state->count == 1) {
		register_code (KC_RSFT);
		register_code (KC_LBRC);
	}else{
		register_code (KC_RSFT);
		register_code (KC_9);	
	}
};

void dance_brackets_left_reset(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code (KC_LBRC);
	}else if (state->count == 1) {
		unregister_code (KC_RSFT);
		unregister_code (KC_LBRC);
	}else{
		unregister_code (KC_RSFT);
		unregister_code (KC_9);
	}
};

void dance_brackets_right_finished(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		register_code (KC_RBRC);
	}else if (state->count == 1) {
		register_code (KC_RSFT);
		register_code (KC_RBRC);
	}else{
		register_code (KC_RSFT);
		register_code (KC_0);	
	}
};

void dance_brackets_right_reset(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code (KC_RBRC);
	}else if (state->count == 1) {
		unregister_code (KC_RSFT);
		unregister_code (KC_RBRC);
	}else{
		unregister_code (KC_RSFT);
		unregister_code (KC_0);
	}
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_EASY_BRACKETS_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_brackets_left_finished, dance_brackets_left_reset),
	[TD_EASY_BRACKETS_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_brackets_right_finished, dance_brackets_right_reset)
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void led_set_user(uint8_t usb_led) {

}
