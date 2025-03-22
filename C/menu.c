#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../H/menu.h"

const vec2 MENU_DEFAULT_POS = {10, 15};
const vec2 MENU_DEFAULT_SIZE = {15, 10};

menu_t globalMenu = {
    .pos = {0, 0},
    .size = {0, 0},
    .selected = 0,
    .currentPage = NULL};

void drawMenuLine(int width, LINETYPE type) {
    int left, middle, right;

    switch (type) {
        case TOP:
            left = MENU_TOP_LEFT;
            middle = MENU_TOP;
            right = MENU_TOP_RIGHT;
            break;
        case SEPARATOR:
            left = MENU_SEPARATOR_LEFT;
            middle = MENU_SEPARATOR_HORIZONTAL;
            right = MENU_SEPARATOR_RIGHT;
            break;
        case BOTTOM:
            left = MENU_BOTTOM_LEFT;
            middle = MENU_BOTTOM;
            right = MENU_BOTTOM_RIGHT;
            break;
        default:
            break;
    }
    printf("%s", SYMBOLS[left]);
    for (int i = 0; i < width; i++) {
        printf("%s", SYMBOLS[middle]);
    }
    printf("%s", SYMBOLS[right]);
}
void drawMenuEntry(char *text, int width, TEXTSTYLE style) {
    int textLength = strlen(text);
    int spaces = (width - 2) - textLength;

    printf("%s", SYMBOLS[MENU_LEFT]);
    printf(" ");

    switch (style) {
        case TITLE: {
            int spacesLeft = floor((float)spaces / 2);
            int spacesRight = spaces - spacesLeft;
            for (int i = 0; i < spacesLeft; i++) {
                printf(" ");
            }
            for (int i = 0; i < textLength; i++) {
                if (text[i] >= 'a' && text[i] <= 'z') {
                    printf("%c", text[i] - ('a' - 'A'));
                } else {
                    printf("%c", text[i]);
                }
            }
            for (int i = 0; i < spacesRight; i++) {
                printf(" ");
            }
            break;
        }
        default:
            break;
    }
    printf(" ");
    printf("%s", SYMBOLS[MENU_RIGHT]);
}
void drawMenu(menu_t *menu) {
    vec2 cursorPos = menu->pos;

    // draw topline
    moveCursor(cursorPos);
    drawMenuLine(menu->size.x, TOP);
    cursorPos.y++;

    // draw title
    moveCursor(cursorPos);
    drawMenuEntry(menu->currentPage->title, menu->size.x, TITLE);
    cursorPos.y++;

    // draw separator
    moveCursor(cursorPos);
    drawMenuLine(menu->size.x, SEPARATOR);
    cursorPos.y++;

    // draw entries
    for (int i = 0; i < menu->currentPage->n_entries; i++) {
        moveCursor(cursorPos);
        drawMenuEntry(menu->currentPage->entries[i], menu->size.x, TITLE);
        cursorPos.y++;
    }

    // draw bottom line
    moveCursor(cursorPos);
    drawMenuLine(menu->size.x, BOTTOM);
}

void callMenu(menu_t *menu, vec2 pos, vec2 size, page_t *page, int sel) {
    menu->pos = pos;
    menu->size = size;
    menu->currentPage = page;
    menu->selected = sel;

    drawMenu(menu);
}