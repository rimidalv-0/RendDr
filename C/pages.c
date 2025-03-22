#include "../H/pages.h"


const entry_t mainEntries[] = {
    (entry_t){
        .title = "object page",
        .data = &objectPage
    },
    (entry_t){
        .title = "scene page",
        .data = &scenePage
    },
    (entry_t){
        .title = "camera page",
        .data = &cameraPage
    },
    (entry_t){
        .title = "render page",
        .data = &renderPage
    }
};
const page_t mainPage = {
    .title = "main page",
    .entries = mainEntries,
    .n_entries = sizeof(mainEntries)/sizeof(mainEntries[0])
};
const page_t objectPage = {
    .title = "object page"
};
const page_t scenePage;
const page_t cameraPage;
const page_t renderPage;