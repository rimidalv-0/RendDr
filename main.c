#include <stdio.h>
#include "H/pages.h"
#include "H/types.h"
#include "H/vectors.h"
#include "H/menu.h"
#include "H/actions.h"
#include "H/infoScreen.h"
#include "H/globals.h"

#define charRatio 14.0 / 36.0
#define samples 10
#define reflections 10

page_t *entryPage = &mainPage;
page_t *previousPage;
scene_t scene;

int main() {
    // init gui
    updateWindowSize(&windowSize);
    // globalInfoScreen = initInfoScreen((vec2){1, windowSize.y - 3}, (vec2){windowSize.x, 3});

    vec2 menuPos = {
        floor((float)(windowSize.x - floor((float)windowSize.x / 3)) / 2),
        floor((float)(windowSize.y - floor((float)windowSize.y / 2)) / 2)};
    vec2 menuSize = {
        floor((float)windowSize.x / 3),
        floor((float)windowSize.y / 2)};

    drawBuffer(NULL, windowSize);

    // callInfoScreen(&globalInfoScreen);
    // writeInfoScreen(&globalInfoScreen, "WELCOME", 1, CENTER);

    page_t *page = &mainPage;
    void *context[] = {
        [CONTEXT_PAGE] = &page};

    // enter the program
    do {
        updateWindowSize(&windowSize);
        char key = getKey();
        if (key == 'm') {
            entry_t *selection;
            // while (((selection = selectFromMenu(page, menuPos, menuSize)) != NULL)) {
            //     if (!selection->handler) break;
            //     selection->handler(selection->data, context);
            // }
            do {
                selection = selectFromMenu(page, menuPos, menuSize);
                if (!selection || !selection->handler) break;
                selection->handler(selection->data, context);
            } while (1);
            page = &mainPage;
        }
    } while (1);
    return 0;
}