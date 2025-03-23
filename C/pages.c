#include "../H/pages.h"

typedef void (*action)(void *data);
void pageHandler(void *entryData, void **context) {
    page_t **location = (page_t **)context[CONTEXT_PAGE];
    page_t *source = (page_t *)entryData;

    *location = source;
}

void sceneActionHandler(void *entryData, void **context) {
    action func = (action)entryData;
    scene_t *scene = (scene_t *)context[CONTEXT_SCENE];
    func(scene);
}

entry_t mainEntries[] = {
    (entry_t){
        .title = "objects menu",
        .data = &objectPage,
        .handler = pageHandler},
    (entry_t){
        .title = "scene menu",
        .data = &scenePage,
        .handler = pageHandler},
    (entry_t){
        .title = "camera menu",
        .data = &cameraPage,
        .handler = pageHandler},
    (entry_t){
        .title = "render menu",
        .data = &renderPage,
        .handler = pageHandler}};
page_t mainPage = {
    .title = "main menu",
    .entries = mainEntries,
    .n_entries = sizeof(mainEntries) / sizeof(mainEntries[0])};

entry_t objectEntries[] = {
    (entry_t){
        .title = "<-",
        .data = &mainPage,
        .handler = pageHandler},
    (entry_t){
        .title = "import object",
        .data = importObject,
        .handler = sceneActionHandler},
};
page_t objectPage = {
    .title = "object page",
    .entries = objectEntries,
    .n_entries = sizeof(objectEntries) / sizeof(objectEntries[0])};

entry_t sceneEntries[] = {

};
page_t scenePage = {
    .title = "scene page",
    .entries = sceneEntries,
    .n_entries = sizeof(sceneEntries) / sizeof(sceneEntries[0])};

entry_t cameraEntries[] = {

};
page_t cameraPage = {
    .title = "camera page",
    .entries = cameraEntries,
    .n_entries = sizeof(cameraEntries) / sizeof(cameraEntries[0])};

entry_t renderEntries[] = {

};
page_t renderPage = {
    .title = "render page",
    .entries = renderEntries,
    .n_entries = sizeof(renderEntries) / sizeof(renderEntries[0])};