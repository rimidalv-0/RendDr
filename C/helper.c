#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "../H/helper.h"

void clearBuffer() {
    while (getchar() != '\n');
    return;
}

void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Replace '\n' with '\0'
    }
}

void moveCursor(vec2 pos) {
    printf("\033[%d;%dH", pos.y, pos.x);
}

void resetCursor() {
    printf("\033[H");
}

void drawBuffer(float **buffer, vec2 windowSize) {
    if (!buffer) {
        for (int i = 0; i < windowSize.y; i++) {
            printf("\n");
        }
    }

    return;
}

void rawMode_enable() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
void rawMode_disable() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void redrawChunk(vec2 pos, vec2 size, char *chunk) {
    vec2 cursorPos = pos;
    moveCursor(cursorPos);

    int chunk_i = 0;
    int chunkLength = strlen(chunk);

    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            if (chunk_i < chunk_i) {
                printf("%c", chunk[chunk_i]);
            } else {
                printf(" ");
            }
            chunk_i++;
        }
        cursorPos.y++;
        moveCursor(cursorPos);
    }
}