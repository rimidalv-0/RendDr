#ifndef MENU_H
#define MENU_H

typedef enum {
    MAINMENU,
    SCENEMENU,
    OBJECTMENU
} PAGEID;
typedef struct page {
    char *title;
    PAGEID *subPages;
    PAGEID parentPage;
} page;


void drawMenu(page *page) {
    printf("%s", page->title);
    printf("%s", page.subPages[0].title);
}

void menu(PAGEID pageid) {
    page objectMenu;
    page sceneMenu;
    objectMenu.title = "OBJECT MENU";
    sceneMenu.title = "SCENE MENU";
    PAGEID mainMenuPages[] = {MAINMENU, SCENEMENU};
    page mainMenu = {"MAIN MENU", mainMenuPages, MAINMENU};

    page *pages[] = {
        [MAINMENU] = &mainMenu,
        [OBJECTMENU] = &objectMenu,
        [SCENEMENU] = &sceneMenu};

    drawMenu(pages[pageid]);
}

#endif
