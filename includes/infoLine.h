#ifndef INFOLINE_H
#define INFOLINE_H

typedef enum {
    LEFT,
    CENTER,
    RIGHT
} MODE;

void clearInfoLine(int width);

void drawInfoLine(vec2 start, vec2 end);

void printInfoLine(int windowHeigh, int windowWidth, char *text, int mode);

#endif