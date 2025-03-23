#ifndef PAGES_H
#define PAGES_H

#include "menu.h"
#include "actions.h"

typedef enum {
    CONTEXT_MENU,
    CONTEXT_SCENE,
    CONTEXT_INFOSCREEN,
    CONTEXT_COUNT,
    CONTEXT_PAGE
} CONTEXT_ID;

extern page_t mainPage;
extern page_t objectPage;
extern page_t scenePage;
extern page_t cameraPage;
extern page_t renderPage;

#endif