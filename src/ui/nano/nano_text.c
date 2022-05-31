#include <string.h>
#include "iota/addresses.h"
#include "nano_text.h"
#include "nano_types.h"

/* ----------- BUILDING MENU / TEXT ARRAY ------------- */
void get_main_menu(char *msg)
{
    memset(msg, '\0', MENU_MAIN_LEN * TEXT_LEN);

    uint8_t i = 0;

    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "Connect");
    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN,"About");
    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN,"Exit App");
}

void get_about_menu(char *msg)
{
    memset(msg, '\0', MENU_ABOUT_LEN * TEXT_LEN);

    uint8_t i = 0;

    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "Version");
    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "More Info");
    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "Back");
}

void get_more_info_menu(char *msg)
{
    memset(msg, '\0', MENU_MORE_INFO_LEN * TEXT_LEN);

    uint8_t i = 0;

    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "Please visit");
    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "iota.org/sec");
    strncpy(msg + (i++ * TEXT_LEN), TEXT_LEN, "for more info.");
}

void get_address_menu(char *msg)
{
    // address is 81 characters long + 9 char checksum
    memset(msg, '\0', MENU_ADDR_LEN * TEXT_LEN);

    uint8_t i = 0, j = 0, chunk_sz = 6;

    // 15 chunks of 6 characters
    for (; i < MENU_ADDR_LEN; i++) {
        strncpy(msg + (i * TEXT_LEN), ui_state.addr + (j++ * 6), chunk_sz);
        msg[i * TEXT_LEN + 6] = ' ';

        if (i == MENU_ADDR_LEN - 1)
            break;

        strncpy(msg + (i * TEXT_LEN) + 7, ui_state.addr + (j++ * 6), chunk_sz);
    }
}
