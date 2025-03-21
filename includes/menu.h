#ifndef MENU_H
#define MENU_H

typedef enum {
    MAINMENU,
    SCENEMENU,
    OBJECTMENU,
    CAMMENU,
    PAGE_COUNT
} PAGEID;

typedef struct page {
    char *title;
    PAGEID *subPages;
    int n_subPages;
    PAGEID parentPage;
} page;


void drawMenu(page *pages, PAGEID pageid) {
    page current = pages[pageid];
    printf("\n%s\n",current.title);
    for(int i = 0; i < current.n_subPages; i++){
        PAGEID subId = current.subPages[i];
        printf("%s\n", pages[subId].title);
    }
}

void menu(PAGEID pageid) {
    PAGEID mainMenuPages[] = {CAMMENU, SCENEMENU, OBJECTMENU};
    page pages[PAGE_COUNT];

    pages[MAINMENU] = (page){
        .title = "MAIN MENU",
        .subPages = mainMenuPages,
        .n_subPages = sizeof(mainMenuPages)/sizeof(mainMenuPages[0]),
        .parentPage = MAINMENU
    };

    pages[SCENEMENU] = (page){
        .title = "SCENE MENU",
        .subPages = NULL,
        .n_subPages = 0,
        .parentPage = MAINMENU
    };

    pages[OBJECTMENU] = (page){
        .title = "OBJECT MENU",
        .subPages = NULL,
        .n_subPages = 0,
        .parentPage = MAINMENU
    };

    pages[CAMMENU] = (page){
        .title = "CAMERA MENU",
        .subPages = NULL,
        .n_subPages = 0,
        .parentPage = MAINMENU
    };

    drawMenu(pages,pageid);
}

#endif
