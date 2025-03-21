#ifndef MENU_H
#define MENU_H

#include "vectors.h"

typedef enum {
    MAINMENU,
    SCENEMENU,
    OBJECTMENU,
    CREATEOBJECT,
    CAMMENU,
    PAGE_COUNT
} PAGEID;

typedef enum {
    TITLE,
    NORMAL,
    UNSELECTED,
    SELECTED
} TEXTMODE;

typedef enum {
    LEFT,
    CENTER,
    RIGHT
} TEXTALIGNMENT;

typedef enum {
    TOP,
    BOTTOM,
    SEPARATOR
} LINEMODE;

typedef struct action {
    char *title;
    void (*function)();
} action;

typedef struct page {
    char *title;
    int n_subPages;
    struct page *subPages;
    PAGEID parentPage;
    int n_actions;
    action *actions;
} page;

void printMenuLine(int width, LINEMODE mode);

void printMenuText(char *text, int width, TEXTMODE mode, TEXTALIGNMENT pos);

void drawMenu(page page, int selected, vec2 pos, vec2 dim);

int selectFromMenu(PAGEID pageid);

void menu(PAGEID pageid, scene *scene);

#endif
