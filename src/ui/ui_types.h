#ifndef UI_TYPES_H
#define UI_TYPES_H

#include <stdint.h>
#include "iota/bundle.h"

/// length of one text line
#define TEXT_LEN 21
#define TOTAL_GLYPHS GLYPH_NONE

// Different positions a text can have
typedef enum { TOP_H, TOP, MID, BOT, BOT_H } UI_TEXT_POS;

#define BUTTON_L 0
#define BUTTON_R 1
#define BUTTON_B 2

#define BUTTON_BAD 255

// UI STATES
typedef enum {
    STATE_INIT,
    STATE_WELCOME,
    STATE_IGNORE,
    STATE_ABOUT,
    STATE_VERSION,
    STATE_MORE_INFO,
    STATE_DISP_ADDR,     // Host displays pubkey on ledger
    STATE_TX_ADDR,       // Display full address in TX
    STATE_DISP_ADDR_CHK, // Abbreviated address with Checksum
    STATE_PROMPT_TX,
    STATE_BIP_PATH,
    STATE_EXIT = 255
} UI_STATES;

// GLYPH TYPES
typedef enum {
    GLYPH_CONFIRM,
    GLYPH_UP,
    GLYPH_DOWN,
    GLYPH_CHECK,
    GLYPH_CROSS,
    GLYPH_WARN,
    GLYPH_DASH,
    GLYPH_LOAD,
    GLYPH_IOTA,
    GLYPH_NONE
} UI_GLYPH_TYPES;

// Size of Menu
#define MENU_INIT_LEN 6
#define MENU_WELCOME_LEN 3
#define MENU_ABOUT_LEN 3
#define MENU_ADDR_LEN 7
#define MENU_MORE_INFO_LEN 3

typedef struct UI_TEXT_CTX {

    // half_top/bot are text lines half off the screen
    // to make text menus appear scrollable
    char half_top[TEXT_LEN];
    char top_str[TEXT_LEN];
    char mid_str[TEXT_LEN];
    char bot_str[TEXT_LEN];
    char half_bot[TEXT_LEN];

} UI_TEXT_CTX;

typedef struct UI_GLYPH_CTX {

    // flags for turning on/off certain glyphs
    char glyph[TOTAL_GLYPHS + 1];

} UI_GLYPH_CTX;

typedef struct UI_STATE_CTX {

    // tx information
    int64_t val;
    bool display_full_value;

    char addr[90];

    uint8_t state;
    uint8_t menu_idx;

    uint8_t backup_state;
    uint8_t backup_menu_idx;

} UI_STATE_CTX;

extern UI_TEXT_CTX ui_text;
extern UI_GLYPH_CTX ui_glyphs;
extern UI_STATE_CTX ui_state;

#endif // UI_TYPES_H
