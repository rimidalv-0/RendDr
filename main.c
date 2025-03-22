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

    typedef enum {
        ACTION_RENAME_SCENE,
        ACTION_COUNT
    } ACTIONID;

    typedef enum {
        PAGE_MAIN,
        PAGE_OBJECT,
        PAGE_CAMERA,
        PAGE_SCENE,
        PAGE_RENDER,
        PAGE_COUNT
    } PAGEID;

    action actions[ACTION_COUNT];
    actions[ACTION_RENAME_SCENE] = (action){
        .title = "rename scene",
        .function = someAction};

    page pages[PAGE_COUNT];

    pages[PAGE_SCENE] = (page){
        .title = "scene menu"};

    pages[PAGE_OBJECT] = (page){
        .title = "object menu"};

    page *mainSubPages[] = {&pages[PAGE_OBJECT], &pages[PAGE_SCENE]};
    action *mainActions[] = {&actions[ACTION_RENAME_SCENE]};
    pages[PAGE_MAIN] = (page){
        .title = "main menu",
        .subPages = mainSubPages,
        .n_subPages = sizeof(mainSubPages) / sizeof(mainSubPages[0]),
        .actions = mainActions,
        .n_actions = sizeof(mainActions) / sizeof(mainActions[0])};

    scene scene;

    vec2 menustart = {15, 20};
    vec2 menuend = {30, 25};
    
    menu(menustart, menuend, &pages[PAGE_MAIN], 1);

    return 0;
}
