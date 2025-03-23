
#include "../H/actions.h"

object_t *createObject(scene_t *scene) {
    scene->n_objects++;
    scene->objects = realloc(scene->objects, sizeof(object_t) * scene->n_objects);

    return &scene->objects[scene->n_objects - 1];
}
void changeObjectColor(object_t *object, vec3 col) {
    object->mat = col;
}
void changeObjectColorWrapper(scene_t *scene) {
    object_t *object = NULL;  // = selectObject("select object", scene->objects, scene->n_objects);

    printf("select color: ");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    clearBuffer();

    changeObjectColor(object, (vec3){a, b, c});
}
void renameObject(object_t *object, char name[64]) {
    if (strlen(name) == 0) {
        printf("enter object name: ");
        fgets(name, 64, stdin);
        removeNewline(name);
    }
    strncpy(object->name, name, 64);
    return;
}
void moveObject(object_t *object, vec3 pos) {
    object->pos = pos;
}
void moveObjectWrapper(scene_t *scene) {
    object_t *object = NULL;  // selectObject("select object", scene->objects, scene->n_objects);

    if (!object) {
        return;
    }

    printf("enter new object position: ");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    clearBuffer();

    moveObject(object, (vec3){a, b, c});
}
void scaleObject(object_t *object, vec3 scale) {
    object->scale = scale;
}
vec3 *createVertex(object_t *object) {
    object->mesh.n_vertices++;
    object->mesh.verticies = realloc(object->mesh.verticies, sizeof(vec3) * object->mesh.n_vertices);

    return &object->mesh.verticies[object->mesh.n_vertices - 1];
}
void positionVertex(vec3 *vertex, vec3 pos) {
    vertex->x = pos.x;
    vertex->y = pos.y;
    vertex->z = pos.z;

    return;
}
face_t *createFace(object_t *object) {
    object->mesh.n_faces++;
    object->mesh.faces = realloc(object->mesh.faces, sizeof(face_t) * object->mesh.n_faces);

    return &object->mesh.faces[object->mesh.n_faces - 1];
}

void fillFace(face_t *face, int a, int b, int c) {
    face->a = a;
    face->b = b;
    face->c = c;
    return;
}
void importFromObj(object_t *object, FILE *file) {
    char line[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        char *identifier = strtok(line, " ");
        if (identifier) {
            if (strcmp(identifier, "o") == 0) {
                char *name = strtok(NULL, " ");
                removeNewline(name);
                renameObject(object, name);
                continue;
            }
            if (strcmp(identifier, "v") == 0) {
                vec3 *vertex = createVertex(object);

                char *x = strtok(NULL, " ");
                char *y = strtok(NULL, " ");
                char *z = strtok(NULL, " ");

                vec3 pos = (vec3){atof(x), atof(y), atof(z)};

                positionVertex(vertex, pos);
                continue;
            }
            if (strcmp(identifier, "f") == 0) {
                face_t *face = createFace(object);

                char *a = strtok(NULL, " ");
                char *b = strtok(NULL, " ");
                char *c = strtok(NULL, " ");

                fillFace(face, atoi(a), atoi(b), atoi(c));
                continue;
            }
        }
    }
    for (int i = 0; i < object->mesh.n_faces; i++) {
        vec3 a = object->mesh.verticies[object->mesh.faces[i].a];
        vec3 b = object->mesh.verticies[object->mesh.faces[i].b];
        vec3 c = object->mesh.verticies[object->mesh.faces[i].c];

        object->mesh.faces[i].normal = normVec(crossProduct(subVec(c, a), subVec(b, a)));
    }
}

void importObject(scene_t *scene) {
    menu_t listMenu = initMenu((vec2){1, 1}, (vec2){10, 50});

    char dirPath[256];
    DIR *dir;

    rawMode_disable();

    do {
        writeInfoScreen(&globalInfoScreen, "enter directory: ", 1, CENTER);
        fgets(dirPath, sizeof(dirPath), stdin);
        removeNewline(dirPath);

        dir = opendir(dirPath);
        if (!dir) {
            writeInfoScreen(&globalInfoScreen, "no such file or direcory", 1, CENTER);
        }
    } while (!dir);

    struct dirent *entry;
    page_t listPage = initPage(dirPath);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_REG) continue;
        if (!hasExtension(entry->d_name, ".obj")) continue;

        char filePath[512];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
        entry_t file = initEntry(entry->d_name, filePath, NULL);
        addEntry(&listPage, file);
    }

    closedir(dir);
    loadPage(&listMenu, &listPage);
    callMenu(&listMenu, 1);
    getchar();
}

void renameScene(scene_t *scene) {
    printf("Enter scene name: ");
    char sceneName[64];

    if (fgets(sceneName, sizeof(sceneName), stdin) == NULL) {
        printf("Scene was not renamed\n");
        return;
    }

    removeNewline(sceneName);

    if (strlen(sceneName) == 0) {
        snprintf(sceneName, sizeof(sceneName), "default");
    }

    snprintf(scene->name, sizeof(scene->name), "%s", sceneName);
    printf("Scene named: %s", scene->name);
    getchar();
    return;
}
void clearScene(scene_t *scene) {
    renameScene(scene);
    // moveCamera(&scene->camera, (vec3){0, 0, -2});
    for (int i = 0; i < scene->n_objects; i++) {
        free(scene->objects[i].mesh.verticies);
        free(scene->objects[i].mesh.faces);
    }
    free(scene->objects);
    scene->n_objects = 0;
    return;
}
