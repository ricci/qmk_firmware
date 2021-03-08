/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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
#include QMK_KEYBOARD_H

// used for tracking the state
bool is_drag_scroll = false;

// safe range starts at `PLOOPY_SAFE_RANGE` instead.
enum custom_keycodes {
    DRAG_SCROLL = PLOOPY_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, DRAG_SCROLL, KC_BTN3,
          KC_BTN2, DPI_CONFIG
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->event.pressed) {
                // this toggles the state each time you tap it
                is_drag_scroll ^= 1;
            }
            break;
    }
    return true;
}

void process_wheel_user(report_mouse_t* mouse_report, int16_t h, int16_t v) {
    mouse_report->h = 3*h;
    mouse_report->v = 3*v;
}

void process_mouse_user(report_mouse_t* mouse_report, int16_t x, int16_t y) {
    if (is_drag_scroll) {
        mouse_report->h = x;
        mouse_report->v = y;
    } else {
        mouse_report->x = x;
        mouse_report->y = y;
    }
}

