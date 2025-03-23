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

const entry_t objectEntries[] = {

};
const page_t objectPage = {
    .title = "object page",
    .entries = objectEntries,
    .n_entries = sizeof(objectEntries)/sizeof(objectEntries[0])
};

const entry_t sceneEntries[] = {

};
const page_t scenePage = {
    .title = "scene page",
    .entries = sceneEntries,
    .n_entries = sizeof(sceneEntries)/sizeof(sceneEntries[0])
};

const entry_t cameraEntries[] = {

};
const page_t cameraPage = {
    .title = "camera page",
    .entries = cameraEntries,
    .n_entries = sizeof(cameraEntries)/sizeof(cameraEntries[0])
};

const entry_t renderEntries[] = {

};
const page_t renderPage = {
    .title = "render page",
    .entries = renderEntries,
    .n_entries = sizeof(renderEntries)/sizeof(renderEntries[0])
};