#ifndef MENU_H
#define MENU_H


#include "symbols.h"
#include "vectors.h"
#include "helper.h"

extern const vec2 MENU_DEFAULT_POS;
extern const vec2 MENU_DEFAULT_SIZE;


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
typedef void(*data_handler_t)(void *data);
typedef struct entry {
    char *title;
    void *data;
    data_handler_t handler;
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
    struct page *currentPage;
} menu_t;

extern menu_t globalMenu;


void callMenu(menu_t *menu, vec2 pos, vec2 size, page_t *page, int sel);

#endif
