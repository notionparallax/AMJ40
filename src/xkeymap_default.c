#include "keymap_common.h"


// Default
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Keymap 0: Default Layer
     * ,-------------------------------------------------.
     * |Esc | Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| Bs  |
     * |-------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ent |
     * |-------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  /| SFT|FN0|
     * |-------------------------------------------------|
     * |Ctrl|Win |Alt |       Space            |Alt |Ctrl|
     * `-------------------------------------------------'
     */
    KEYMAP(
    //  1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
        D,   O,   H,   E,   R,   T,   Y,   U,   I,   P,  A,  A,\
        D,   O,   H,   E,   R,   T,   Y,   J,   K,   L,  A,\
        D,   O,   H,   E,   R,   T,   Y,   M,   A,   A,  A,\
        A,   A,   A,        A,        A,        A,   A,  A),

    /* Keymap 1: FN Layer
     * ,-------------------------------------------------.
     * | ` |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|Del  |
     * |-------------------------------------------------|
     * |   ,  | . | ; | ' | [ | ] | \ | - | = |PgUp|     |
     * |-------------------------------------------------|
     * |       |Up|Ins|FN1|FN2|VolU|VolD|Mute|PgDn|   |  |
     * |-------------------------------------------------|
     * |Left|Down|Riht|                        |    |    |
     * `-------------------------------------------------'
     */
     KEYMAP(
     //  1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
         F,   R,   U,   S,   T,   R,   A,   T,   E,   P,  A,  A,\
         D,   O,   H,   E,   R,   T,   Y,   J,   K,   L,  A,\
         D,   O,   H,   E,   R,   T,   Y,   M,   A,   A,  A,\
         A,   A,   A,        A,        A,        B,   B,  B),
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
        case KEYPAD_00:
            return (record->event.pressed ?
                    MACRO( T(P0), T(P0), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}
