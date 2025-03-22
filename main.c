#include <stdio.h>

#include "H/types.h"
#include "H/vectors.h"
#include "H/menu.h"
#include "H/actions.h"

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
    page_t objectPage = {
        .title = "object page"};

    entry_t mainEntries[] = {
        (entry_t){
            .title = "object menu",
            .data = &objectPage},
        (entry_t){
            .title = "scene menu",
            .data = &objectPage},
        (entry_t){
            .title = "camera menu",
            .data = &objectPage}};

    page_t mainPage = {
        .title = "main page",
        .entries = mainEntries,
        .n_entries = sizeof(mainEntries) / sizeof(mainEntries[0])};

    page_t *current_page = &mainPage;

    int sel = 0;
    while (1) {
        callMenu(&globalMenu, (vec2){0, 1}, (vec2){10, 15}, current_page, sel);
        char key;
        scanf(" %c", &key);
        clearBuffer();

        switch (key) {
            case 's':
                if (sel >= current_page->n_entries - 1) {
                    break;
                }
                sel++;
                break;
            case 'w':
                if (sel <= 0) {
                    break;
                }
                sel--;
                break;
            case 'e':
                if (sel < current_page->entries) {
                    current_page = (page_t *)current_page->entries[0].data;
                }
            default:
                break;
        }
    }
    return 0;
}
