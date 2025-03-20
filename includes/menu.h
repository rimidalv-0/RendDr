#ifndef MENU_H
#define MENU_H

typedef struct page {
    char *title;
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

void menu(pageID pageID) {
    page objectMenu = {"OBJECT MENU", {NULL}, NULL};
    page sceneMenu = {"SCENE MENU", {NULL}, NULL};
    page mainMenu = {"MAIN MENU", {&sceneMenu, &objectMenu}, NULL};

    page *pages[] = {
        [MAINMENU] = &mainMenu,
        [OBJECTMENU] = &objectMenu,
        [SCENEMENU] = &sceneMenu
    };
    
    drawMenu(pages[pageID]);
}

#endif