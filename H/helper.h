#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
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

void redrawChunk(vec2 pos, vec2 size, char* chunk);

int hasExtension(const char* filename, const char* ext);

vec2 updateWindowSize(vec2* window);

char getKey();

char* my_strdup(const char* s);

#endif