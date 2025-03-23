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

vec2 windowSize = {100, 20};

page_t *entryPage = &mainPage;
page_t *previousPage;
scene_t scene;

int main() {
    // init gui
    globalInfoScreen = initInfoScreen((vec2){1, windowSize.y - 3}, (vec2){windowSize.x, 3});
    globalMenu = initMenu((vec2){20, 10}, (vec2){15, 10});

    drawBuffer(NULL, windowSize);

    callInfoScreen(&globalInfoScreen);
    writeInfoScreen(&globalInfoScreen, "WELCOME", 1, CENTER);

    void *context[] = {
        [CONTEXT_MENU] = &globalMenu,
        [CONTEXT_INFOSCREEN] = &globalInfoScreen};

    // enter the program
    while (1) {
        rawMode_enable();
        int sel = 0;
        char key;
        scanf(" %c", &key);
        if (key == 'm') {  // open menu
            loadPage(&globalMenu, entryPage);
            while (key != 'q') {  // until the menu is closed
                callMenu(&globalMenu, sel);
                scanf(" %c", &key);
                switch (key) {
                    case 'w':
                        if (sel <= 0) {
                            break;
                        }
                        sel--;
                        break;
                    case 's':
                        if (sel >= globalMenu.currentPage->n_entries - 1) {
                            break;
                        }
                        sel++;
                        break;
                        case 'r':
                        if(globalMenu.previousPage){
                            globalMenu.currentPage = globalMenu.previousPage;
                        }
                        break;
                    case 'e': {
                        if (!globalMenu.currentPage->entries[sel].handler) {
                            break;
                        }
                        entry_t selectedEntry = globalMenu.currentPage->entries[sel];
                        selectedEntry.handler(selectedEntry.data, context);
                        break;
                    }
                    default:
                        break;
                }
                redrawChunk(globalMenu.pos, globalMenu.size, " ");
            }
            redrawChunk(globalMenu.pos, globalMenu.size, " ");
            rawMode_disable();
        }
    }
    
    return 0;
}