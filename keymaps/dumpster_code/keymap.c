#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM combo_tab[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_esc, KC_ESC),
};

enum custom_keycodes {
    _DOT = SAFE_RANGE,
    _SLASH,
    _PTR,
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
        case _DOT:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_COMMA);
                    set_mods(mod_state);
                }
                else {
                    tap_code(KC_DOT);
                }
            }
            break;
        case _SLASH:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_BSLS);
                    set_mods(mod_state);
                }
                else {
                    tap_code(KC_PSLS);
                }
            }
            break;
        case _PTR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;

        return false;   
    }
    return true;
}

#define L_1_SPC LT(1, KC_SPC)
#define L_3_SPC LT(3, KC_SPC)
#define L_2_BSPC LT(2, KC_BSPC)
#define L_3_BSPC LT(3, KC_BSPC)
#define M_SFT_CR MT(MOD_LSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      XXXXXXX,    KC_Y,    KC_U,    KC_I,    KC_O, KC_QUES,  
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_SCLN,    KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_EQL,    KC_N,    KC_M,    KC_P,    _DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MO(3), L_2_BSPC, KC_LSFT,     KC_ENT, L_1_SPC, KC_UNDS
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HOME, KC_LCTL, KC_LALT,  KC_END, KC_TRNS,                      KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, L_3_BSPC, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST,    _PTR, XXXXXXX,                      XXXXXXX, KC_EXLM, KC_AMPR, KC_PIPE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LBRC, KC_LABK, KC_LCBR, KC_LPRN, XXXXXXX,                      KC_TRNS, KC_RPRN, KC_RCBR, KC_RABK, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, XXXXXXX,                      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, L_3_SPC, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PAST, KC_PSLS, KC_PLUS, KC_PMNS, XXXXXXX,                      XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, XXXXXXX, KC_BSLS, XXXXXXX, KC_BSPC, XXXXXXX,                      XXXXXXX,  KC_SPC,    KC_1,    KC_2,    KC_3, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};

#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
