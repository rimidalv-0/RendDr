#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../H/infoScreen.h"

infoScreen_t initInfoScreen(vec2 pos, vec2 size) {
    return (infoScreen_t){
        .pos = pos,
        .size = size,
        .data = NULL};
}
void callInfoScreen(infoScreen_t *screen) {
    vec2 cursorPos = screen->pos;

    moveCursor(cursorPos);
    printf("%s", SYMBOLS[INFOSCREEN_TOP_LEFT]);
    for (int i = 1; i < screen->size.x - 1; i++) {
        printf("%s", SYMBOLS[INFOSCREEN_TOP]);
    }
    printf("%s", SYMBOLS[INFOSCREEN_TOP_RIGHT]);
    cursorPos.y++;

    for (int i = 1; i < screen->size.y - 1; i++) {
        moveCursor(cursorPos);
        printf("%s", SYMBOLS[INFOSCREEN_LEFT]);
        for (int j = 1; j < screen->size.x - 1; j++) {
            printf(" ");
        }
        printf("%s", SYMBOLS[INFOSCREEN_RIGHT]);
        cursorPos.y++;
    }
    moveCursor(cursorPos);
    printf("%s", SYMBOLS[INFOSCREEN_BOTTOM_LEFT]);
    for (int i = 1; i < screen->size.x - 1; i++) {
        printf("%s", SYMBOLS[INFOSCREEN_BOTTOM]);
    }
    printf("%s", SYMBOLS[INFOSCREEN_BOTTOM_RIGHT]);
}
void writeInfoScreen(infoScreen_t *screen, char *data, int row, MODE mode) {
    vec2 cursorPos;
    cursorPos.y = screen->pos.y + row;
    switch (mode) {
        case LEFT:
            cursorPos.x = screen->pos.x + 2;
            break;
        case CENTER: {
            int spaces = (floor)((float)(screen->size.x - strlen(data)) / 2);
            cursorPos.x = screen->pos.x + spaces;
            break;
        }
        case RIGHT:
            cursorPos.x = ((screen->pos.x + screen->size.x) - strlen(data))- 2;

            break;
        default:
            break;
    }
    moveCursor(cursorPos);
    printf("%s", data);
}