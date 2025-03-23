#ifndef INFOSCREEN_H
#define INFOSCREEN_H

#include "helper.h"
#include "types.h"
#include "symbols.h"

typedef struct infoScreen {
    vec2 pos;
    vec2 size;
    char *data;
} infoScreen_t;
typedef enum {
    LEFT,
    CENTER,
    RIGHT
} MODE;

infoScreen_t initInfoScreen(vec2 pos, vec2 size);
void writeInfoScreen(infoScreen_t *screen, char *data, int row, MODE mode);
void callInfoScreen(infoScreen_t *screen);


#endif
