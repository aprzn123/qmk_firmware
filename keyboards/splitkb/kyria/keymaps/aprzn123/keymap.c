/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    BASE = 0,
    QWERTY,
    NUMS,
    NAV,
    FNS,
    MOUSE
};

enum encmodes {
    TABS = 0,
    LEFTRIGHT,
    UPDOWN,
    VOLUME,
    BRIGHTNESS,
    DFMAP
};

enum custom_keycodes {
    ENC_TOG = SAFE_RANGE
};

enum encmodes curr_mode = TABS;
bool encmode_sel = true;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_TOG:
            if (record->event.pressed) {encmode_sel = !encmode_sel;}
            break;
    }
    return true;
}


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,  KC_SCLN, TG(MOUSE),
     KC_LCTL , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,KC_O,KC_QUOT,
     TG(QWERTY) , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LSFT, KC_ENT ,  KC_BSPC , KC_SPC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, ENC_TOG,
                                KC_LALT , KC_LGUI, MO(NAV), KC_SPC , KC_BSPC,     KC_ENT , KC_RSFT ,MO(NUMS), KC_RGUI, KC_RALT
    ),

    [QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P, TG(MOUSE),
     KC_LCTL , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,KC_QUOT,
     KC_TRNS , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LSFT, KC_ENT ,  KC_BSPC , KC_SPC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, ENC_TOG,
                                KC_LALT , KC_LGUI, MO(NAV), KC_SPC , KC_BSPC,     KC_ENT , KC_RSFT ,MO(NUMS), KC_RGUI, KC_RALT
    ),

     [NUMS] = LAYOUT(
       KC_GRV , KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                                     KC_BSLS, KC_7, KC_8, KC_9, KC_PIPE, _______,
       _______, KC_PLUS, KC_DLR , KC_PERC, KC_CIRC, KC_MINS,                                     KC_LCBR, KC_4, KC_5, KC_6, KC_RCBR, _______,
       _______, KC_UNDS, KC_EXLM, KC_AT  , KC_HASH, KC_EQL , _______, _______, _______, _______, KC_LBRC, KC_1, KC_2, KC_3, KC_RBRC, _______,
                                  _______, _______, _______, _______, KC_DEL , _______, _______, _______, KC_0, _______
     ),

     [NAV] = LAYOUT(
       KC_ESC , _______, _______, KC_UP  , _______, _______,                                     _______, KC_HOME, KC_END , _______, _______, _______,
       _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGUP, KC_PGDN,
       _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

     [FNS] = LAYOUT(
       _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                                     _______, _______, _______, _______, _______, _______,
       _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                                     _______, _______, _______, _______, _______, _______,
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

     [MOUSE] = LAYOUT(
       _______, _______, _______, KC_WH_U, _______, _______,                                     _______, _______, _______, _______, _______, _______,
       _______, _______, KC_BTN2, KC_WH_D, KC_BTN1, _______,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
       _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

const rgblight_segment_t PROGMEM lbase[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 10, 13, 255, 150},
        {10, 10, HSV_BLUE}
        );

const rgblight_segment_t PROGMEM lnum[] = RGBLIGHT_LAYER_SEGMENTS(
        {10, 10, HSV_WHITE}
        );

const rgblight_segment_t PROGMEM lnav[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 10, HSV_WHITE}
        );

const rgblight_segment_t PROGMEM lmouse[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 3, HSV_RED},
        {6, 3, HSV_RED},
        {10, 3, HSV_RED},
        {16, 3, HSV_RED}
        );

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        lbase,
        lnum,
        lnav,
        lmouse
        );


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        /*
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        */
        // Host Keyboard Layer Status
        //oled_write_P(PSTR("Layer: "), false);
        //switch (get_highest_layer(layer_state|default_layer_state)) {
            //case BASE:
                //oled_write_P(PSTR("BASE\n"), false);
                //break;
            //case NUMS:
                //oled_write_P(PSTR("NUMS\n"), false);
                //break;
            //case NAV:
                //oled_write_P(PSTR("NAV\n"), false);
                //break;
            //case MOUSE:
                //oled_write_P(PSTR("MOUSE\n"), false);
                //break;
            //default:
                //oled_write_P(PSTR("Undefined\n"), false);
        //}

        // Write host Keyboard LED Status to OLEDs
        /*
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
        */
        oled_write_P(PSTR("\nq w f p b   j l u y\n\na r s t g   m n e i o\nz x c v d   k h"), false);
    } else {
        //oled_write_P(PSTR("\nq w f r b   y u i o p\na s d t g   m n e l\n\nz x c v j   k h"), false);
        /*
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
        */
        //static const char PROGMEM TABS_S[] = PSTR("TABS");
        //static const char PROGMEM LEFTRIGHT_S[] = PSTR("LEFTRIGHT");
        //static const char PROGMEM UPDOWN_S[] = PSTR("UPDOWN");
        //static const char PROGMEM BRIGHTNESS_S[] = PSTR("BRIGHTNESS");
        //static const char PROGMEM DFMAP_S[] = PSTR("DFMAP");

        switch (curr_mode) {
            case TABS:
                oled_write_ln_P(PSTR("BRIGHTNESS"), false);
                oled_write_ln_P(PSTR("DFMAP"), false);
                oled_write_ln_P(PSTR("TABS"), true);
                oled_write_ln_P(PSTR("LEFTRIGHT"), false);
                oled_write_ln_P(PSTR("UPDOWN"), false);
                break;
            case LEFTRIGHT:
                oled_write_ln_P(PSTR("DFMAP"), false);
                oled_write_ln_P(PSTR("TABS"), false);
                oled_write_ln_P(PSTR("LEFTRIGHT"), true);
                oled_write_ln_P(PSTR("UPDOWN"), false);
                oled_write_ln_P(PSTR("VOLUME"), false);
                break;
            case UPDOWN:
                oled_write_ln_P(PSTR("TABS"), false);
                oled_write_ln_P(PSTR("LEFTRIGHT"), false);
                oled_write_ln_P(PSTR("UPDOWN"), true);
                oled_write_ln_P(PSTR("VOLUME"), false);
                oled_write_ln_P(PSTR("BRIGHTNESS"), false);
                break;
            case VOLUME:
                oled_write_ln_P(PSTR("LEFTRIGHT"), false);
                oled_write_ln_P(PSTR("UPDOWN"), false);
                oled_write_ln_P(PSTR("VOLUME"), true);
                oled_write_ln_P(PSTR("BRIGHTNESS"), false);
                oled_write_ln_P(PSTR("DFMAP"), false);
                break;
            case BRIGHTNESS:
                oled_write_ln_P(PSTR("UPDOWN"), false);
                oled_write_ln_P(PSTR("VOLUME"), false);
                oled_write_ln_P(PSTR("BRIGHTNESS"), true);
                oled_write_ln_P(PSTR("DFMAP"), false);
                oled_write_ln_P(PSTR("TABS"), false);
                break;
            case DFMAP:
                oled_write_ln_P(PSTR("VOLUME"), false);
                oled_write_ln_P(PSTR("BRIGHTNESS"), false);
                oled_write_ln_P(PSTR("DFMAP"), true);
                oled_write_ln_P(PSTR("TABS"), false);
                oled_write_ln_P(PSTR("LEFTRIGHT"), false);
                break;
        }
        if (encmode_sel) {oled_write_P(PSTR("selecting..."), false);}
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    } else if (index == 1) {
        if (encmode_sel && !clockwise) {
            switch (curr_mode) {
                case TABS:
                    curr_mode = LEFTRIGHT;
                    break;
                case LEFTRIGHT:
                    curr_mode = UPDOWN;
                    break;
                case UPDOWN:
                    curr_mode = VOLUME;
                    break;
                case VOLUME:
                    curr_mode = BRIGHTNESS;
                    break;
                case BRIGHTNESS:
                    curr_mode = DFMAP;
                    break;
                case DFMAP:
                    curr_mode = TABS;
                    break;
            }
        } else if (encmode_sel) {
            switch (curr_mode) {
                case TABS:
                    curr_mode = DFMAP;
                    break;
                case DFMAP:
                    curr_mode = BRIGHTNESS;
                    break;
                case BRIGHTNESS:
                    curr_mode = VOLUME;
                    break;
                case VOLUME:
                    curr_mode = UPDOWN;
                    break;
                case UPDOWN:
                    curr_mode = LEFTRIGHT;
                    break;
                case LEFTRIGHT:
                    curr_mode = TABS;
                    break;
            }
        }
    }
    return false;
}
#endif

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(0, true);
}

    //rgblight_set_layer_state(3, get_highest_layer(layer_state|default_layer_state) == MOUSE);
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, IS_LAYER_ON_STATE(state, NUMS));
    rgblight_set_layer_state(2, IS_LAYER_ON_STATE(state, NAV));
    rgblight_set_layer_state(3, IS_LAYER_ON_STATE(state, MOUSE));

    state = update_tri_layer_state(state, NUMS, NAV, FNS);
    return state;
} 
