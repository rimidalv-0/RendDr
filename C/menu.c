#include "../H/menu.h"

void drawMenuLine(int width, LINETYPE type) {
    LINETYPE left, middle, right;

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
    printf(SYMBOLS[left]);
    for (int i = 0; i < width; i++) {
        printf(SYMBOLS[middle]);
    }
    printf(SYMBOLS[right]);
}

void drawMenuEntry(char *text, int width, TEXTSTYLE style) {
    int textLength = strlen(text);
    int spaces = (width - 2) - textLength;

    printf(SYMBOLS[MENU_LEFT]);
    printf(" ");

    switch (style) {
        case TITLE:
            int spacesLeft = floor((float)spaces / 2);
            int spacesRight = spaces - spacesLeft;
            for (int i = 0; i < spacesLeft; i++) {
                printf(" ");
            }
            for (int i = 0; i < textLength; i++) {
                if (text[i] >= 'a' && text[i] <= 'z') {
                    printf("%c", text[i] - ('a' - 'A'));
                }else{
                    printf("%c", text[i]);
                }
            }
            for (int i = 0; i < spacesRight; i++) {
                printf(" ");
            }
            break;

        default:
            break;
    }
    printf(" ");
    printf(SYMBOLS[MENU_RIGHT]);
}

void drawMenu(vec2 pos, vec2 dim, page *page, int selected) {
    // draw topline
    moveCursor(pos);
    drawMenuLine(dim.x, TOP);
    pos.y++;

    // draw title
    moveCursor(pos);
    drawMenuEntry(page->title, dim.x, TITLE);
    pos.y++;

    // draw separator
    moveCursor(pos);
    drawMenuLine(dim.x, SEPARATOR);
    pos.y++;

    // draw subpages
    for (int i = 0; i < fmin(dim.y, page->n_subPages); i++) {
        moveCursor(pos);
        drawMenuEntry(page->subPages[i]->title, dim.x, UNSELECTED);
        pos.y++;
    }

    // draw actions
    for (int i = 0; i < fmin(dim.y, page->n_actions); i++) {
        moveCursor(pos);
        drawMenuEntry(page->actions[i]->title, dim.x, UNSELECTED);
        pos.y++;
    }

    // draw bottom line
    moveCursor(pos);
    drawMenuLine(dim.x, BOTTOM);
}

void menu(vec2 pos, vec2 dim, page *page, int sel) {
    drawMenu(pos, dim, page, sel);
}