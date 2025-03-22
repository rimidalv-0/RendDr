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

#endif