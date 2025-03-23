#ifndef MENU_H
#define MENU_H

#include "symbols.h"
#include "vectors.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
typedef void (*data_handler_t)(void *data);
typedef struct entry {
    char *title;
    const void *data;
    data_handler_t handler;
} entry_t;
typedef struct page {
    char *title;
    const entry_t *entries;
    int n_entries;
} page_t;
typedef struct menu {
    vec2 pos;
    vec2 size;
    int selected;
    struct page *currentPage;
} menu_t;

menu_t initMenu(vec2 pos, vec2 size);
void loadPage(menu_t *menu, page_t *page);
void callMenu(menu_t *menu,  int sel);

#endif
