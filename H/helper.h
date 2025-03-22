#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <string.h>
#include "types.h"
#include "vectors.h"

void clearBuffer();

void removeNewline(char* str);

void moveCursor(vec2 pos);

void resetCursor();

void drawBuffer(float** buffer, vec2 windowSize);

#endif