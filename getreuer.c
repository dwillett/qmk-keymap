// Copyright 2021-2025 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @mainpage Pascal Getreuer's QMK keymap
 *
 * This is my Quantum Mechanical Keyboard (QMK) keymap. Who knew a keyboard
 * could do so much?
 *
 * This repo uses the Apache License 2.0 except where otherwise indicated. See
 * LICENSE.txt for details.
 *
 * For further documentation of this keymap's features, see
 * <https://getreuer.info/posts/keyboards>
 */

#if __has_include("user_song_list.h")
#include "user_song_list.h"
#endif

enum layers {
  BASE,
  SYM,
  NAV,
  NUM,
  FUN,
  EXT,
};

enum custom_keycodes {
  ARROW = SAFE_RANGE,
  UPDIR,
  STDCC,
  USRNAME,
  TMUXESC,
  SRCHSEL,
  RGBBRI,
  RGBNEXT,
  RGBHUP,
  RGBHRND,
  RGBDEF1,
  RGBDEF2,
  // Macros invoked through the Magic key.
  M_DOCSTR,
  M_EQEQ,
  M_INCLUDE,
  M_ION,
  M_MENT,
  M_MKGRVS,
  M_QUEN,
  M_THE,
  M_TMENT,
  M_UPDIR,
  M_NBSP,
  M_NOOP,
};

// The "magic" key is the Alternate Repeat Key.
#define MAGIC QK_AREP

// Short aliases for home row mods and other tap-hold keys.
#define HRM_A LGUI_T(KC_A)
#define HRM_R LALT_T(KC_R)
#define HRM_S LCTL_T(KC_S)
#define HRM_T LSFT_T(KC_T)
#define HRM_D LT(NUM, KC_D)
#define OS_LSFT OSM(MOD_LSFT)

#define HRM_N RSFT_T(KC_N)
#define HRM_E RCTL_T(KC_E)
#define HRM_I LALT_T(KC_I)
#define HRM_O RGUI_T(KC_O)
#define HRM_H LT(EXT, KC_H)
#define OS_RSFT OSM(MOD_RSFT)

#define NAV_BSP LT(NAV, KC_BSPC)
#define SYM_SPC LT(SYM, KC_SPC)
#define FUN_ESC LT(FUN, KC_ESC)
#define EXT_ENT LT(EXT, KC_ENT)

// Other aliases
#define ZOOMIN LGUI_T(KC_EQL)
#define ZOOMOUT LGUI_T(KC_MINS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_LR(  // Base layer: Colemak DH.
    KC_EQL , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
    KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,
    CW_TOGG, HRM_A  , HRM_R  , HRM_S  , HRM_T  , KC_G   ,
    OS_LSFT, KC_Z   , KC_X   , KC_C   , HRM_D  , KC_V   ,
                                                 NAV_BSP, FUN_ESC,

                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSLS,
                      KC_M   , HRM_N  , HRM_E  , HRM_I  , HRM_O  , KC_QUOT,
                      KC_K   , HRM_H  , KC_COMM, KC_DOT , KC_SLSH, OS_RSFT,
             EXT_ENT, SYM_SPC
  ),

  [NAV] = LAYOUT_LR(  // Navigation layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, C(KC_PGUP), C(KC_PGDN), XXXXXXX, XXXXXXX,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN1,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      _______, _______, _______, _______, _______, _______,
                      C(KC_X), KC_HOME, KC_UP  , KC_END , KC_PGUP, _______,
                      C(KC_C), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
                      C(KC_V), C(KC_Z), KC_BSPC, C(KC_Y), XXXXXXX, _______,
             _______, XXXXXXX
  ),

  [SYM] = LAYOUT_LR(  // Symbol layer. 
    KC_GRV , KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_AT  ,
    KC_EXLM, KC_COMM, KC_LCBR, KC_RCBR, KC_PERC, KC_QUES,
    KC_HASH, KC_CIRC, KC_EQL , KC_UNDS, KC_DLR , KC_ASTR,
    KC_TILD, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_SLSH,
                                                 KC_COLN, KC_BSLS,

                      _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, _______,
                      KC_GRV , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN  , _______,
                      KC_DQUO, KC_BSPC, KC_TAB , KC_SPC , KC_ENT , _______,
                      KC_QUOT, KC_MINS, KC_AMPR, KC_PLUS, _______, _______,
             _______, _______
  ),

  [NUM] = LAYOUT_LR(  // Number layer.
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_A   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_B   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_C   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      KC_TILD, KC_CIRC, KC_HASH, KC_DLR , KC_EXLM, KC_AT  ,
                      XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_COLN, KC_PERC,
                      XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PMNS, KC_PPLS,
                      XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, KC_PAST,
             KC_P0  , KC_PEQL
  ),

  [FUN] = LAYOUT_LR(  // Funky fun layer.
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_A   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_B   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_C   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      KC_F16 , KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, KC_EJCT,
                      KC_F17 , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F13 ,
                      ZOOMIN , KC_F4  , KC_F5  , KC_F6  , KC_F11 , KC_F14 ,
                      ZOOMOUT, KC_F1  , KC_F2  , KC_F3  , KC_F12 , KC_F15 ,
             KC_VOLD, KC_VOLU
  ),

  [EXT] = LAYOUT_LR(  // Mouse and extras.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    OM_SLOW, KC_LALT, KC_LCTL, KC_LSFT, SELLINE, XXXXXXX,
    _______, KC_LGUI, C(KC_V), C(KC_A), C(KC_C), C(KC_X),
                                                 KC_DEL , MS_BTN1,

                      _______, _______, _______, _______, _______, _______,
                      OM_W_U , MS_BTN1, OM_U   , MS_BTN2, SRCHSEL, _______,
                      OM_W_D , OM_L   , OM_D   , OM_R   , OM_SLOW, _______,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
             MS_BTN1, XXXXXXX
  ),

};

// A cheap pseudorandom generator.
uint8_t myrand(void) {
  static uint16_t state = 1;
#ifdef __CHIBIOS__  // Use high-res timer on ChibiOS
  state += (uint16_t)chVTGetSystemTimeX();
#else
  state += timer_read();
#endif
  state *= UINT16_C(36563);
  return state >> 8;
}

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
// const uint16_t del_combo[] PROGMEM = {KC_BSPC, KC_ESC, COMBO_END};
// const uint16_t j_k_combo[] PROGMEM = {KC_J, KC_K, COMBO_END};
// const uint16_t h_comm_combo[] PROGMEM = {HRM_H, KC_COMM, COMBO_END};
// const uint16_t comm_dot_combo[] PROGMEM = {KC_COMM, HRM_DOT, COMBO_END};
// const uint16_t f_n_combo[] PROGMEM = {KC_F, HRM_N, COMBO_END};
// clang-format off
combo_t key_combos[] = {
    // COMBO(del_combo, KC_DEL),          // J and , => activate Caps Word.
    // COMBO(j_k_combo, KC_BSLS),           // J and K => backslash
    // COMBO(h_comm_combo, KC_QUOT),        // H and , => '
    // COMBO(comm_dot_combo, KC_SCLN),      // , and . => ;
    // COMBO(f_n_combo, OSL(FUN)),          // F and N => FUN layer
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Custom shift keys (https://getreuer.info/posts/keyboards/custom-shift-keys)
///////////////////////////////////////////////////////////////////////////////
#ifdef COMMUNITY_MODULE_CUSTOM_SHIFT_KEYS_ENABLE
const custom_shift_key_t custom_shift_keys[] = {
    // {HRM_DOT, KC_QUES},
    // {KC_COMM, KC_EXLM},
    // {KC_MINS, KC_SCLN},
    // {KC_SLSH, KC_BSLS},
    // {KC_MPLY, KC_MNXT},
};
#endif  // COMMUNITY_MODULE_CUSTOM_SHIFT_KEYS_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Tap-hold configuration (https://docs.qmk.fm/tap_hold)
///////////////////////////////////////////////////////////////////////////////
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case HRM_R:
    case HRM_E:
      return TAPPING_TERM - 45;
    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case HRM_N:
    case HRM_H:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

#ifdef CHORDAL_HOLD
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
    case NAV_BSP:
      return true;
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

///////////////////////////////////////////////////////////////////////////////
// Autocorrect (https://docs.qmk.fm/features/autocorrect)
///////////////////////////////////////////////////////////////////////////////
#ifdef AUTOCORRECT_ENABLE
bool apply_autocorrect(uint8_t backspaces, const char* str, char* typo,
                       char* correct) {
  for (uint8_t i = 0; i < backspaces; ++i) {
    tap_code(KC_BSPC);
  }
  send_string_with_delay_P(str, TAP_CODE_DELAY);
  return false;
}
#endif  // AUTOCORRECT_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT_LSHIFT);  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_COLN:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Sentence case (https://getreuer.info/posts/keyboards/sentence-case)
///////////////////////////////////////////////////////////////////////////////
#ifdef COMMUNITY_MODULE_SENTENCE_CASE_ENABLE
char sentence_case_press_user(uint16_t keycode, keyrecord_t* record,
                              uint8_t mods) {
  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT_RALT)) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      case KC_A ... KC_Z:
        return 'a';  // Letter key.

      case KC_DOT:  // Both . and Shift . (?) punctuate sentence endings.
      case KC_EXLM:
      case KC_QUES:
        return '.';

      case KC_COMM:
        return shifted ? '.' : '#';

      case KC_2 ... KC_0:  // 2 3 4 5 6 7 8 9 0
      case KC_AT ... KC_RPRN:  // @ # $ % ^ & * ( )
      case KC_MINS ... KC_SCLN:  // - = [ ] backslash ;
      case KC_UNDS ... KC_COLN:  // _ + { } | :
      case KC_GRV:
        return '#';  // Symbol key.

      case KC_SPC:
        return ' ';  // Space key.

      case KC_QUOT:
      case KC_DQUO:
        return '\'';  // Quote key.
    }
  }

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
  return '\0';
}
#endif  // COMMUNITY_MODULE_SENTENCE_CASE_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Repeat key (https://docs.qmk.fm/features/repeat_key)
///////////////////////////////////////////////////////////////////////////////
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
  // Unpack tapping keycode for tap-hold keys.
  switch (keycode) {
#ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
#ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
  }

#ifdef COMMUNITY_MODULE_SENTENCE_CASE_ENABLE
  if (is_sentence_case_primed() &&
      sentence_case_press_user(keycode, record, *remembered_mods) == 'a') {
    *remembered_mods |= MOD_BIT_LSHIFT;
  }
#endif  // COMMUNITY_MODULE_SENTENCE_CASE_ENABLE

  // Forget Shift on most letters when Shift or AltGr are the only mods. Some
  // letters are excluded, e.g. for "NN" and "ZZ" in Vim.
  switch (keycode) {
    case KC_A ... KC_H:
    case KC_K ... KC_M:
    case KC_O ... KC_U:
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT_RALT)) == 0) {
        *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
// RGB Matrix Lighting (https://docs.qmk.fm/features/rgb_matrix)
///////////////////////////////////////////////////////////////////////////////
#if RGB_MATRIX_ENABLE
// The following logic controls the RGB Matrix light level with a convenient
// 3-state setting---off, dim, or full---and turns off automatically and with
// smooth transitions when the keyboard is idle.

#include <lib/lib8tion/lib8tion.h>

static struct {
  uint32_t timer;
  uint8_t event_count;
  uint8_t val;
  uint8_t val_start;
  uint8_t val_end;
} lighting = {0};

static void lighting_set_val(uint8_t val) {
  lighting.val = val;
  lighting.val_end = val;
  if (lighting.val_start != lighting.val_end) {
    lighting.timer = timer_read32();
  }
}

/** Cycles between off, 40% brightness, and max brightness. */
static void lighting_cycle_3_state(void) {
  if (lighting.val == 0) {
    lighting_set_val((RGB_MATRIX_MAXIMUM_BRIGHTNESS * 2 + 2) / 5);
  } else if (lighting.val < RGB_MATRIX_MAXIMUM_BRIGHTNESS) {
    lighting_set_val(RGB_MATRIX_MAXIMUM_BRIGHTNESS);
  } else {
    lighting_set_val(0);
  }
}

static void lighting_set_palette(uint8_t palette) {
  if (lighting.val == 0) {
    lighting_cycle_3_state();
  }
  rgb_matrix_enable_noeeprom();
  rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * palette, 255,
                             rgb_matrix_get_val());
}

static void lighting_preset(uint8_t effect, uint8_t palette) {
  lighting_set_palette(palette);
  rgb_matrix_mode_noeeprom(effect);
  rgb_matrix_set_speed_noeeprom(100);
}

static void lighting_init(void) {
  lighting.val_start = 0;
  lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
  lighting_set_val(RGB_MATRIX_MAXIMUM_BRIGHTNESS);
}

static void lighting_set_sleep_timer(void) {
  if (lighting.val_start == lighting.val_end) {
    const uint32_t duration =
        (lighting.event_count <= 10) ? UINT32_C(5000) : UINT32_C(30000);
    lighting.timer = (timer_read32() + duration) | 1;
  }
}

/** This function should be called on every key event to keep lights awake. */
static void lighting_activity_trigger(void) {
  if (lighting.val > 0) {
    lighting.event_count = qadd8(lighting.event_count, 1);
    if (lighting.val_end == 0) {
      lighting_set_val(lighting.val);  // Wake lighting.
    } else {
      lighting_set_sleep_timer();
    }
  }
}

static void lighting_task(void) {
  if (!lighting.timer) {
    return;
  }  // Early return if sleeping.
  const uint32_t diff = timer_read32() - lighting.timer;

  if (lighting.val_start != lighting.val_end) {
    const uint8_t t = (diff <= 511) ? (uint8_t)(diff / 2) : 255;

    hsv_t hsv = rgb_matrix_get_hsv();
    hsv.v = (t == 255) ? lighting.val_end
                       : lerp8by8(lighting.val_start, lighting.val_end,
                                  ease8InOutCubic(t));
    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);

    if (t == 255) {  // Transition complete.
      lighting.val_end = rgb_matrix_get_val();
      lighting.val_start = lighting.val_end;
      if (lighting.val_end == 0) {  // Sleep.
        lighting.timer = 0;
        lighting.event_count = 0;
      } else {
        lighting_set_sleep_timer();
      }
    }
  } else if (diff < UINT32_MAX / 2) {  // Sleep timeout expired; begin fading.
    lighting.val_end = 0;
  }
}
#endif  // RGB_MATRIX_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Debug logging
///////////////////////////////////////////////////////////////////////////////
#if !defined(NO_DEBUG) && defined(COMMUNITY_MODULE_KEYCODE_STRING_ENABLE)
#pragma message "dlog_record: enabled"

KEYCODE_STRING_NAMES_USER(
    KEYCODE_STRING_NAME(ARROW), KEYCODE_STRING_NAME(UPDIR),
    KEYCODE_STRING_NAME(STDCC), KEYCODE_STRING_NAME(USRNAME),
    KEYCODE_STRING_NAME(TMUXESC), KEYCODE_STRING_NAME(SRCHSEL),
    KEYCODE_STRING_NAME(SELWORD), KEYCODE_STRING_NAME(SELWBAK),
    KEYCODE_STRING_NAME(SELLINE), KEYCODE_STRING_NAME(RGBBRI),
    KEYCODE_STRING_NAME(RGBNEXT), KEYCODE_STRING_NAME(RGBHUP),
    KEYCODE_STRING_NAME(RGBHRND), KEYCODE_STRING_NAME(RGBDEF1),
    KEYCODE_STRING_NAME(RGBDEF2), );

static void dlog_record(uint16_t keycode, keyrecord_t* record) {
  if (!debug_enable) {
    return;
  }
  uint8_t layer = read_source_layers_cache(record->event.key);
  bool is_tap_hold = IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode);
  xprintf("L%-2u ", layer);  // Log the layer.
  if (IS_COMBOEVENT(record->event)) {  // Combos don't have a position.
    xprintf("combo   ");
  } else {  // Log the "(row,col)" position.
    xprintf("(%2u,%2u) ", record->event.key.row, record->event.key.col);
  }
  xprintf("%-4s %-7s %s\n",  // "(tap|hold) (press|release) <keycode>".
          is_tap_hold ? (record->tap.count ? "tap" : "hold") : "",
          record->event.pressed ? "press" : "release",
          get_keycode_string(keycode));
}
#else
#pragma message "dlog_record: disabled"
#define dlog_record(keycode, record)
#endif  // !defined(NO_DEBUG) && defined(COMMUNITY_MODULE_KEYCODE_STRING_ENABLE)

///////////////////////////////////////////////////////////////////////////////
// Status LEDs
///////////////////////////////////////////////////////////////////////////////
#ifdef STATUS_LED_1
// LED 1 indicates when any layer above the SYM layer is active.
layer_state_t layer_state_set_user(layer_state_t state) {
  STATUS_LED_1(get_highest_layer(layer_state) > SYM);
  return state;
}
#endif  // STATUS_LED_1

#ifdef STATUS_LED_2
// LED 2 indicates when Sentence case is in primed to capitalize the next key.
void sentence_case_primed(bool primed) { STATUS_LED_2(primed); }
#endif  // STATUS_LED_2

#ifdef STATUS_LED_3
// LED 3 indicates when Caps word is active.
void caps_word_set_user(bool active) { STATUS_LED_3(active); }
#endif  // STATUS_LED_3

///////////////////////////////////////////////////////////////////////////////
// User macro callbacks (https://docs.qmk.fm/feature_macros)
///////////////////////////////////////////////////////////////////////////////

void keyboard_post_init_user(void) {
#if RGB_MATRIX_ENABLE
  lighting_init();
#endif  // RGB_MATRIX_ENABLE

  // Play MUSHROOM_SOUND two seconds after init, if defined and audio enabled.
#if defined(AUDIO_ENABLE) && defined(MUSHROOM_SOUND)
  uint32_t play_init_song_callback(uint32_t trigger_time, void* cb_arg) {
    static float init_song[][2] = SONG(MUSHROOM_SOUND);
    PLAY_SONG(init_song);
    return 0;
  }
  defer_exec(2000, play_init_song_callback, NULL);
#endif  // defined(AUDIO_ENABLE) && defined(MUSHROOM_SOUND)
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef RGB_MATRIX_ENABLE
  lighting_activity_trigger();
#endif  // RGB_MATRIX_ENABLE
  dlog_record(keycode, record);

  return true;
}

void housekeeping_task_user(void) {
#ifdef RGB_MATRIX_ENABLE
  lighting_task();
#endif  // RGB_MATRIX_ENABLE
}
