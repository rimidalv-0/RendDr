#include "../H/menu.h"

menu_t initMenu(vec2 pos, vec2 size) {
    return (menu_t){
        .pos = pos,
        .size = size,
        .selected = 0,
        .currentPage = NULL,
        .previousPage = NULL};
}
void loadPage(menu_t *menu, page_t *page) {
    menu->previousPage = menu->currentPage;
    menu->currentPage = page;
}
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
    for (int i = 1; i < width - 1; i++) {
        printf("%s", SYMBOLS[middle]);
    }
    printf("%s", SYMBOLS[right]);
}
void drawMenuEntry(char *text, int width, TEXTSTYLE style) {
    int textLength = strlen(text);
    int spaces = (width - 4) - textLength;

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

        case UNSELECTED: {
            printf("%s", SYMBOLS[MENU_UNSELECTED]);
            printf("%s", text);
            for (int i = 0; i < spaces; i++) {
                printf(" ");
            }
            break;
        }
        case SELECTED: {
            printf("%s", SYMBOLS[MENU_SELECTED]);
            printf("%s", text);
            for (int i = 0; i < spaces; i++) {
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
void callMenu(menu_t *menu, int sel) {
    vec2 cursorPos = menu->pos;
    moveCursor(cursorPos);
    drawMenuLine(menu->size.x, TOP);
    cursorPos.y++;

    moveCursor(cursorPos);
    drawMenuEntry(menu->currentPage->title, menu->size.x, TITLE);
    cursorPos.y++;

    // draw separator
    moveCursor(cursorPos);
    drawMenuLine(menu->size.x, SEPARATOR);
    cursorPos.y++;

    // draw entries
    for (int i = 0; i < menu->currentPage->n_entries; i++) {
        int type = (i == sel) ? SELECTED : UNSELECTED;
        moveCursor(cursorPos);
        drawMenuEntry(menu->currentPage->entries[i].title, menu->size.x, type);
        cursorPos.y++;
    }

    // draw bottom line
    moveCursor(cursorPos);
    drawMenuLine(menu->size.x, BOTTOM);
}