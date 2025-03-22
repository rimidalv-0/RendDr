#ifndef INFOLINE_H
#define INFOLINE_H


#include "helper.h"
#include "types.h"
#include "symbols.h"

const vec2 INFOLINE_DEFAULT_POS = {0,0};
const vec2 INFOLINE_DAFAULT_SIZE = {0,0};

typedef struct infoLine {
    vec2 pos;
    vec2 size;
} infoLine_t;

extern infoLine_t globalInfoLine;

typedef enum {
    LEFT,
    CENTER,
    RIGHT
} MODE;
void clearInfoLine(int width);
void drawInfoLine(vec2 start, vec2 end);
void printInfoLine(int windowWidth, char *text, int mode);

#endif