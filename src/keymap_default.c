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

// Stagger
// #define KEYMAP(
//     K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B,
//     K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A,
//     K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,
//     K30, K31, K32,      K33,      K34,      K35, K36, K37
//       1,    2,    3,    4,    5,    6,     7,    8,    9,    10,  11,     12
KEYMAP(
         ESC,   Q,    W,    E,    R,    T,     Y,    U,        I,        O,        P, BSPC,  \
         TAB,   A,    S,    D,    F,    G,     H,    J,        K,        L,   SCOLON, \
      LSHIFT,   Z,    X,    C,    V,    B,     N,    M,    COMMA,      DOT,     SLSH, \
       LCTRL, FN0, LALT,        ENT,         SPC,       LBRACKET, RBRACKET,      FN1),
KEYMAP(
      TRNS,    1,    2,    3,    4,    5,     6,    7,    8,     9,     0,   DEL,  \
      TRNS,   F1,   F2,   F3,   F4,   F5,    F6,   F7,   F8,    F9,   F10,    \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  TRNS, TRNS, TRNS, GRAVE, QUOTE,    \
      TRNS, TRNS, TRNS,       TRNS,        TRNS,       TRNS, MINUS, EQUAL),
KEYMAP(
      TRNS,  TRNS,   UP,  TRNS, TRNS, TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, DEL,  \
      TRNS,  LEFT, DOWN, RIGHT, TRNS, TRNS,  TRNS, TRNS, TRNS, F11,   F12,       \
      TRNS,  TRNS, MUTE,  TRNS, TRNS, TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS,       \
      TRNS,  TRNS, TRNS,        TRNS,        TRNS,       TRNS, TRNS, TRNS),
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
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_BACKLIGHT_DECREASE(),
    [3] = ACTION_BACKLIGHT_INCREASE()
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
 * Macro definition
 */
// enum macro_id {
//     USCORE,
//     ENEMAYUSCULA,
// };
//
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//     keyevent_t event = record->event;
//     //uint8_t tap_count = record->tap_count;
//
//     switch (id) {
//         case USCORE:
//             return (event.pressed ?
//                     MACRO( D(LSFT), T(MINUS), U(LSFT), END ) :
//                     MACRO( END ) );
//         case ENEMAYUSCULA:
//             return (event.pressed ?
//                     MACRO( D(LSHIFT), T(GRV), T(N), U(LSHIFT), END ) :
//                     MACRO( END ) );
//     }
//     return MACRO_NONE;
// }
//
//
// const uint16_t PROGMEM fn_actions[] = {
//     [0] = ACTION_MACRO(USCORE),
//     [1] = ACTION_MACRO(ENEMAYUSCULA),
// };
