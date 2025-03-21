#include "menu.h"
#include "symbols.h"
#include "actions.h"

void printMenuLine(int width, LINEMODE mode) {
    SYMBOLID left, middle, right;
    switch (mode) {
        case TOP:
            left = MENU_TOP_LEFT;
            middle = MENU_TOP;
            right = MENU_TOP_RIGHT;
            break;
        case SEPARATOR:
            left = MENU_SEPARATOR_LEFT;
            middle = MENU_SEPARATOR_HORIZONTAL;
            right = MENU_SEPARATOR_RIGHT;
            break;
        case BOTTOM:
            left = MENU_BOTTOM_LEFT;
            middle = MENU_BOTTOM;
            right = MENU_BOTTOM_RIGHT;
            break;
        default:
            break;
    }
    printf(SYMBOLS[left]);
    for (int i = 0; i < width; i++) {
        printf(SYMBOLS[middle]);
    }
    printf(SYMBOLS[right]);
}

void printMenuText(char *text, int width, TEXTMODE mode, TEXTALIGNMENT pos) {
    printf(SYMBOLS[MENU_LEFT]);
    printf(" ");
    switch (mode) {
        case NORMAL:
            printf(text);
            break;
        case UNSELECTED:
            printf(" ");
            printf(text);
            break;
        case SELECTED:
            printf(SYMBOLS[MENU_SELECTED]);
            printf(text);
            break;
        default:
            break;
    }
    printf(" ");
    printf(SYMBOLS[MENU_RIGHT]);
}

void drawMenu(page page, int selected, vec2 pos, vec2 dim) {
    moveCursor(pos);
    printMenuLine(dim.x, TOP);
    pos.y++;
    moveCursor(pos);
    printMenuText(page.title, dim.x, NORMAL, CENTER);
    pos.y++;
    moveCursor(pos);
    printMenuLine(dim.x, SEPARATOR);
    pos.y++;
    moveCursor(pos);
    int selectedLine = 1;
    for (int i = 0; i < page.n_subPages; i++) {
        TEXTMODE mode = (selectedLine == selected) ? SELECTED : UNSELECTED;
        printMenuText(page.subPages[i].title, dim.x, mode, CENTER);
        pos.y++;
        moveCursor(pos);
        selectedLine++;
    }
    for (int i = 0; i < page.n_actions; i++) {
        TEXTMODE mode = (selectedLine == selected) ? SELECTED : UNSELECTED;
        printMenuText(page.actions[i].title, dim.x, mode, CENTER);
        pos.y++;
        moveCursor(pos);
        selectedLine++;
    }
    moveCursor(pos);
    printMenuLine(dim.x, BOTTOM);
}

int selectFromMenu(PAGEID pageid) {
    vec2 pos = {25, 5};
    vec2 dim = {25, 10};
}

void menu(PAGEID pageid, scene *scene) {
    page pages[PAGE_COUNT];

    page sceneMenu = {
        .title = "scene menu",
        .n_subPages = 0,
        .parentPage = MAINMENU};

    action objectActions[] = {
        {.title = "import object", .function = importObject}
    };
    page objectMenu = {
        .title = "object mendddddddddddddddddddddddddddddddddddddddu",
        .parentPage = MAINMENU,
        .n_actions = sizeof(objectActions) / sizeof(objectActions[0]),
        .actions = objectActions};

    action cameraActions[] = {
        //{.title = "reset camera", .function = resetCamera},
        {.title = "move camera", .function = moveCamera},
        //{.title = "rotate camera", .function = rotateCamera},
        {.title = "change camera fov", .function = (void *)fovCamera}};
    page cameraMenu = {
        .title = "camera menu",
        .parentPage = MAINMENU,
        .n_actions = sizeof(cameraActions) / sizeof(cameraActions[0]),
        .actions = cameraActions};

    page mainMenuPages[] = {
        sceneMenu,
        objectMenu,
        cameraMenu};
    page mainMenu = {
        .title = "main menu",
        .subPages = mainMenuPages,
        .n_subPages = sizeof(mainMenuPages) / sizeof(mainMenuPages[0]),
        .parentPage = MAINMENU};

    PAGEID nextPage = pageid;
    selectFromMenu(nextPage);
}