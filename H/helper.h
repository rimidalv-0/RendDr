#ifndef HELPER_H
#define HELPER_H


#include "types.h"
#include "vectors.h"
#include "menu.h"

void clearBuffer();
void removeNewline(char* str);
void moveCursor(vec2 pos);
void resetCursor();
void drawBuffer(float** buffer, vec2 windowSize);

void rawMode_enable();

void rawMode_disable();

void redrawChunk(vec2 pos, vec2 size, char *chunk);

#endif