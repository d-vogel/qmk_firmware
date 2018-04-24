/* Copyright 2018 d-vogel
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
#include "simpleDial.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_MPLY, KC_VOLD, MO(1)  \
),
[1] = LAYOUT(
    KC_MPLY, KC_VOLU, MO(1)  \
),

/*
to suport next/prev when pushing the button. Disable for now, a bit sensitive.
[0] = LAYOUT(
    LT(2, KC_MPLY), KC_VOLD, MO(1)  \
),
[1] = LAYOUT(
    LT(2, KC_MPLY), KC_VOLU, MO(1)  \
),
[2] = LAYOUT(
    LT(2, KC_MPLY), KC_MNXT, MO(3)  \
),
[3] = LAYOUT(
    LT(2, KC_MPLY), KC_MPRV, MO(3)  \
),*/

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
