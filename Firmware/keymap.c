// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-laterz

#include QMK_KEYBOARD_H
#include "gpio.h"

#define LED_NUM_LOCK_PIN GP21 

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(LED_NUM_LOCK_PIN);
}
bool led_update_kb(led_t led_state) {
    
    bool res = led_update_user(led_state);
    if(res) {

    gpio_write_pin(LED_NUM_LOCK_PIN, led_state.num_lock);

    }
    
    return res; 
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┐
     * │Esc│ <-│
     * ├───┼───┼───────┐
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   |
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_CALC, 
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
                 KC_P0,   KC_PDOT
    ),

    /*
     * ┌───┐───┐
     * │Rst│Tab│
     * └───┘───┼───────┐
     * │Num│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_6x4(
        QK_BOOT, _______, 
        _______, _______, _______, _______,
        KC_HOME, KC_UP,   KC_PGUP, _______,
        KC_LEFT, XXXXXXX, KC_RGHT, 
        KC_END,  KC_DOWN, KC_PGDN, _______,
                 KC_INS,   KC_DEL
    )
};

