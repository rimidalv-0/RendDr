#include "../H/menu.h"

page_t initPage(char *title) {
    page_t page = {
        .title = title,
        .entries = NULL,
        .n_entries = 0};
    return page;
}

entry_t initEntry(char *title, void *data, void *handler) {
    entry_t entry = {
        .title = title,
        .data = data,
        .handler = handler};
    return entry;
}

void addEntry(page_t *page, entry_t entry) {
    int n_entries = page->n_entries + 1;
    page->entries = realloc(page->entries, n_entries * sizeof(entry_t));
    page->entries[page->n_entries] = entry;
    page->n_entries = n_entries;
}

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
            for (int i = 1; i < spaces; i++) {
                printf(" ");
            }
            break;
        }
        case SELECTED: {
            printf("%s", SYMBOLS[MENU_SELECTED]);
            printf("%s", text);
            for (int i = 1; i < spaces; i++) {
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

void drawMenu(page_t *page, vec2 pos, vec2 size, int sel) {
    vec2 cursorPos = pos;
    moveCursor(cursorPos);
    drawMenuLine(size.x, TOP);
    cursorPos.y++;

    moveCursor(cursorPos);
    drawMenuEntry(page->title, size.x, TITLE);
    cursorPos.y++;

    // draw separator
    moveCursor(cursorPos);
    drawMenuLine(size.x, SEPARATOR);
    cursorPos.y++;

    // draw entries
    for (int i = 0; i < page->n_entries; i++) {
        int type = (i == sel) ? SELECTED : UNSELECTED;
        moveCursor(cursorPos);
        drawMenuEntry(page->entries[i].title, size.x, type);
        cursorPos.y++;
    }

    // draw bottom line
    moveCursor(cursorPos);
    drawMenuLine(size.x, BOTTOM);
}

entry_t *selectFromMenu(page_t *page, vec2 pos, vec2 size) {
    entry_t selection;

    int sel = 0;
    while (1) {
        drawMenu(page, pos, size, sel);
        char key = getKey();

        switch (key) {
            case 'w':
                if (sel <= 0) break;
                sel--;
                break;
            case 's':
                if (sel >= page->n_entries - 1) break;
                sel++;
                break;
            case 'e':
                return &page->entries[sel];
            case 'q':
                return NULL;
            default:
                break;
        }
    }
}
