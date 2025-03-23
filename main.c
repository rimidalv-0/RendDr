#include <stdio.h>

#include "H/pages.h"
#include "H/types.h"
#include "H/vectors.h"
#include "H/menu.h"
#include "H/actions.h"
#include "H/infoScreen.h"

#define charRatio 14.0 / 36.0
#define samples 10
#define reflections 10

vec2 windowSize = {100, 50};

infoScreen_t globalInfoScreen;
menu_t globalMenu;
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

    // enter the program
    while (1) {
        rawMode_enable();
        int sel = 0;
        char key;
        scanf(" %c", &key);
        if (key == 'm') {         // open menu
            while (key != 'q') {  // until the menu is closed
                loadPage(&globalMenu, entryPage);
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
                        if(sel >= globalMenu.currentPage->n_entries - 1){
                            break;
                        }
                        sel++;
                        break;
                    case 'e':
                        break;
                    default:
                        break;
                }
            }

            redrawChunk(globalMenu.pos, globalMenu.size, " ");
            rawMode_disable();
        }
    }
    return 0;
}