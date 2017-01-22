#include "keymap_common.h"


// Default
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif

// -----------------------------------------------------------
// | Esc | Q | W | E | R | T | Y | U | I | O | P | Backspace |
// -----------------------------------------------------------
// | Tab | A | S | D | F | G | H | J | K | L | Enter |
// ---------------------------------------------------
// | Shift | Z | X | C | V | B | N | M | DOT | UP | Shift |
// --------------------------------------------------------
// | Ctrl | FN0 | Alt | FN1 | SPC | LEFT | DOWN | RIGHT |
// ------------------------------------------------------
KEYMAP(
      Esc,  D,  O,  H,  E,  R,  T,  Y,  U,  I,  P,  Backspace,  \
      Tab,  A,  S,  D,  F,  G,  M(0),  J,  K,  L,  Enter,  \
      Shift,  Z,  X,  C,  V,  B,  N,  M,  DOT,  UP,  Shift,  \
      Ctrl,  FN0,  Alt,  FN1,  SPC,  LEFT,  DOWN,  RIGHT,  \
    )//,

    // Keymap 1: green Layer (FN0)

// -----------------------------------------------------------------------------------------------------------------------------------
// | lock | ~ | ` | | | &bull; | &radic; | &pi; | &divide; | × | &para; | &Delta; | <i class="fa fa-bars"></i> |
// -----------------------------------------------------------------------------------------------------------------------------------
// |   | £ | ¢ | € | ¥ | ^ | ° | = | { | } | BSLS |
// ------------------------------------------------
// |   | % | © | ® | ™ | ℅ | LBRC | RBRC | ² |   |   |
// ---------------------------------------------------
// |   |   |   |   |   |   |   |   |
// ---------------------------------

// KEYMAP(
//       TRNS,  ~,  GRAVE,  |,  &bull;,  &radic;,  &pi;,  &divide;,  ×,  &para;,  &Delta;,  M(0),  \
//       TRNS,  £,  ¢,  €,  ¥,  ^,  °,  =,  {,  },  BSLS,  \
//       TRNS,  %,  ©,  ®,  ™,  ℅,  LBRC,  RBRC,  ²,  TRNS,  TRNS,  \
//       TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  \
// )
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_BACKLIGHT_DECREASE(),
    [2] = ACTION_BACKLIGHT_INCREASE()
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif

/*
 * Action macro definition
 */
enum macro_id {
    KEYPAD_00 = 0,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 0: // this would trigger when you hit a key mapped as M(0)
          if (record->event.pressed) {
            // this sends the string 'c7xtermx -n ' when the macro executes
            return MACRO( I(255), T(C), T(7), T(X), T(T), T(E), T(R), T(M), T(X), T(SPC), T(MINS), T(N), END  );
          }
          break;
        }
    return MACRO_NONE;
}
