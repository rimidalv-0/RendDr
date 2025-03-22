#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "symbols.h"
#include "vectors.h"
#include "helper.h"


typedef enum {
    TITLE,
    UNSELECTED,
    SELECTED
} TEXTSTYLE;

typedef enum {
    TOP,
    SEPARATOR,
    BOTTOM
} LINETYPE;

typedef struct action {
    char *title;
    void (* function)();
} action;

typedef struct page {
    char *title;
    int n_subPages;
    struct page **subPages;
    struct page *parentPage;
    int n_content;
    char **content;
    int n_actions;
    action **actions;
} page;

/// @brief creates a menu
/// @param pos top left position of menu x,y
/// @param dim size of menu x,y
/// @param page adrres of page to display
/// @param sel which menu entry is selected
void menu(vec2 pos, vec2 dim, page *page, int sel);

#endif

