#ifndef MENU_H
#define MENU_H

struct page page;

typedef struct page {
    char *title;
    unsigned int n_subpages;
    struct page **subPages;
    struct page *parentPage;
} page;

typedef enum {
    MAINMENU,
    SCENEMENU,
    OBJECTMENU
} pageID;

void drawMenu(page *page) {
    printf("%s", page->title);
}

void menu(pageID page) {
    page sceneMenu = {"SCENE MENU"};
    page objectMenu = {"OBJECT MENU"};
    page mainMenuSubPages[] = {sceneMenu, objectMenu};
    page mainMenu = {"MAIN MENU", *mainMenuSubPages};
    page arr[] = {
        [MAINMENU] = mainMenu,
        [SCENEMENU] = sceneMenu,
        [OBJECTMENU] = objectMenu};
    drawMenu(arr[page]);
}

#endif