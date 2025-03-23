#ifndef INFOSCREEN_H
#define INFOSCREEN_H

#include "helper.h"
#include "types.h"
#include "symbols.h"

typedef struct{
    vec2 pos;
    vec2 size;
    char *data;
} infoScreen_t;
typedef enum {
    LEFT,
    CENTER,
    RIGHT
} ALIGN_TEXT;


/// @brief initislize cleen infoscreen
/// @param pos topLeft position 
/// @param size 
/// @return infoscreen with given dimensions
infoScreen_t initInfoScreen(vec2 pos, vec2 size);

//--- needs refining to how display and send data to screen

/// @brief sends the data to the infoscreen
/// @param screen adress of the screen to write into
/// @param data 1D array of characters to write
/// @param row in what row 
/// @param mode 
void writeInfoScreen(infoScreen_t *screen, char *data, int row, ALIGN_TEXT mode);
void callInfoScreen(infoScreen_t *screen);

#endif
