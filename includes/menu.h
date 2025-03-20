#ifndef MENU_H
#define MENU_H

typedef struct menuOption{
    char *title;
} menuOption;

typedef enum {
    MAINMENU,
    SCENEMENU,
    OBJECTMENU
}pages;

menuOption mainMenu = { "MAIN MENU"};
menuOption sceneMenu = { "SCENE MENU"};
menuOption objectMenu = { "OBJECT MENU"};



void drawMenu(menuOption *page){
    printf("%s", page->title);
}

void menu(pages page){
    menuOption arr[] = {
        [MAINMENU] = mainMenu,
        [SCENEMENU] = sceneMenu,
        [OBJECTMENU] = objectMenu
    };
    drawMenu(&arr[page]);
}

#endif