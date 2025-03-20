#ifndef INFOLINE_H
#define INFOLINE_H

void drawInfoLine(vec2 start, vec2 dim){
    
    moveCursor(start);
    
    printf(SYMBOLS[INFOLINE_TOP_LEFT]);
    for(int i = 1; i < dim.x -1; i++){
        printf(SYMBOLS[INFOLINE_TOP]);
    }
    printf(SYMBOLS[INFOLINE_TOP_RIGHT]);
    start.y++;
    
    
    for(int i = 1; i < dim.y - 1; i++){
        moveCursor(start);
        printf(SYMBOLS[INFOLINE_LEFT]);
        for(int j = 1; j < dim.x - 1; j++){
            printf(" ");
        }
        printf(SYMBOLS[INFOLINE_RIGHT]);
        start.y++;
    }
    
    moveCursor(start);
    printf(SYMBOLS[INFOLINE_BOTTOM_LEFT]);
    for(int i = 1; i < dim.x -1; i++){
        printf(SYMBOLS[INFOLINE_BOTTOM]);
    }
    printf(SYMBOLS[INFOLINE_BOTTOM_RIGHT]);
}

void clearInfoLine(int windowWidth){
    printf("\033[2;2h");
    for(int i = 2; i < windowWidth -2;i++){
        printf(" ");
    }
    
}

void printInfoLine(int windowHeigh, int windowWidth, char *text, int mode) {
    int textLenght = strlen(text);

    //moveCursor(3, 0, 0, 0);
    printf(SYMBOLS[INFOLINE_TOP_LEFT]);
    for (int i = 1; i < windowWidth - 1; i++) {
        printf(SYMBOLS[INFOLINE_TOP]);
    }
    printf(SYMBOLS[INFOLINE_TOP_RIGHT]);
    //moveCursor(0, 1, 0, windowWidth);

    printf(SYMBOLS[INFOLINE_LEFT]);
    switch (mode) {
        case 1:  // centered
            int spaces = (windowWidth - 2) - textLenght;
            int spacesLeft = floor((float)spaces / 2);
            int spacesRight = ceil((float)spaces / 2);

            for (int i = 0; i < spacesLeft; i++) {
                printf(" ");
            }
            printf("%s", text);
            for (int i = 0; i < spacesRight; i++) {
                printf(" ");
            }

            break;
        case 2:  // right
            for (int i = 1; i < (windowWidth - 2) - strlen(text); i++) {
                printf(" ");
            }
            printf("%s", text);
            printf(" ");
            break;
        default:  // left

            printf(" ");
            printf("%s", text);
            for (int i = 1; i < (windowWidth - 2) - strlen(text); i++) {
                printf(" ");
            }

            break;
    }
    printf(SYMBOLS[INFOLINE_RIGHT]);
    //moveCursor(0, 1, 0, windowWidth);

    printf(SYMBOLS[INFOLINE_BOTTOM_LEFT]);
    for (int i = 1; i < windowWidth - 1; i++) {
        printf(SYMBOLS[INFOLINE_BOTTOM]);
    }
    printf(SYMBOLS[INFOLINE_BOTTOM_RIGHT]);
    //moveCursor(0, 1, 0, windowWidth);
}


#endif