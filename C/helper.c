#include "../H/helper.h"

void clearBuffer() {
    while (getchar() != '\n');
    return;
}

void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Replace '\n' with '\0'
    }
}

void moveCursor(vec2 pos) {
    printf("\033[%d;%dH", pos.y, pos.x);
}

void resetCursor(){
    printf("\033[H");
}

void drawBuffer(float **buffer, vec2 windowSize) {
    if(!buffer){
        for(int i = 0; i < windowSize.y;i++){
            printf("\n");
        }
    }
    
    return;
}