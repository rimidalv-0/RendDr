#include <stdio.h>

#include "H/types.h"
#include "H/vectors.h"
#include "H/menu.h"
// #include "actions.h"

#define charRatio 14.0 / 36.0
#define samples 10
#define reflections 10

/* MENU STRUCTURE

MAIN MENU
    SCENE MENU -> DISPLAY SCENE INFO
        RENAME SCENE
        SAVE SCENE
        LAOD SCENE
        RESET SCENE
        PRINT SCENE INFO
    OBJECT MENU -> DISPLAY OBJECTS
        ADD OBJECT
        IMPORT OBJECT
        EXPORT OBJECT
        MOVE OBJECT
        SCALE OBJECT
        ROTATE OBJECT
    CAMERA MENU -> DISPLAY CAMERA SETTINGS
        RESET CAMERA
        MOVE CAMERA
        ROTATE CAMERA
        CHANGE CAMERA FOV
        ? CHANGE CAMERA EFFECT
    RENDER -> DISPLAY RENDER SETTINGS
        RENDER IMAGE
        CHANGE RENDER ENGINE
        CHANGE OUTPUT
        CHANGE RESOLUTION

 */

void someAction() {
    return;
}

int main() {
    // vec2 windowSize = {100, 50};
    // vec2 infoLinePos = {0, windowSize.y - 3};

    

    //scene scene;
    char *entries[] = {"helpp", "okaopdd"};

    page_t page = {
        .title = "main",
        .entries = entries,
        .n_entries = sizeof(entries)/sizeof(entries[0])
    };

    callMenu(&globalMenu, (vec2){0,1}, (vec2){10,15}, &page, 1);
    printf("%s", entries[0]);

    return 0;
}
