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

typedef struct entry {
    char *title;
    void *data;
    void (*handler)(void *, void **);
} entry_t;

typedef struct page {
    char *title;
    entry_t *entries;
    int n_entries;
} page_t;

typedef struct menu {
    vec2 pos;
    vec2 size;
    int selected;
    page_t *currentPage;
    page_t *previousPage;
} menu_t;

page_t initPage(char *title);

entry_t initEntry(char *title, void *data, void *handler);

void addEntry(page_t *page, entry_t entry);

menu_t initMenu(vec2 pos, vec2 size);
void loadPage(menu_t *menu, page_t *page);
void callMenu(menu_t *menu, int sel);

#endif
