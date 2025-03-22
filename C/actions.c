
#include "../H/actions.h"



// obj *createObject(scene_t *scene) {
//     scene->n_objects++;
//     scene->objects = realloc(scene->objects, sizeof(obj) * scene->n_objects);

//     return &scene->objects[scene->n_objects - 1];
// }
// void changeObjectColor(obj *object, vec3 col) {
//     object->mat = col;
// }
// void changeObjectColorWrapper(scene_t *scene) {
//     obj *object = selectObject("select object", scene->objects, scene->n_objects);

//     printf("select color: ");
//     float a,b,c;
//     scanf("%f %f %f", &a ,&b ,&c);
//     clearBuffer();

//     changeObjectColor(object, (vec3){a,b,c});
// }
// void renameObject(obj *object, char name[64]) {
//     if (strlen(name) == 0) {
//         printf("enter object name: ");
//         fgets(name, 64, stdin);
//         removeNewline(name);
//     }
//     strncpy(object->name, name, 64);
//     return;
// }
// void moveObject(obj *object, vec3 pos) {
//     object->pos = pos;
// }
// void moveObjectWrapper(scene *scene) {
//     obj *object = selectObject("select object", scene->objects, scene->n_objects);

//     if(!object){
//         return;
//     }

//     printf("enter new object position: ");
//     float a,b,c;
//     scanf("%f %f %f", &a, &b, &c);
//     clearBuffer();

//     moveObject(object, (vec3){a,b,c});
// }
// void scaleObject(obj *object, vec3 scale) {
//     object->scale = scale;
// }
// vec3 *createVertex(obj *object) {
//     object->mesh.n_vertices++;
//     object->mesh.verticies = realloc(object->mesh.verticies, sizeof(vec3) * object->mesh.n_vertices);

//     return &object->mesh.verticies[object->mesh.n_vertices - 1];
// }
// void positionVertex(vec3 *vertex, vec3 pos) {
//     vertex->x = pos.x;
//     vertex->y = pos.y;
//     vertex->z = pos.z;

//     return;
// }
// face *createFace(obj *object) {
//     object->mesh.n_faces++;
//     object->mesh.faces = realloc(object->mesh.faces, sizeof(face) * object->mesh.n_faces);

//     return &object->mesh.faces[object->mesh.n_faces - 1];
// }

// void fillFace(face *face, int a, int b, int c) {
//     face->a = a;
//     face->b = b;
//     face->c = c;
//     return;
// }
// void importFromObj(obj *object, FILE *file) {
//     char line[256];

//     while (fgets(line, sizeof(line), file) != NULL) {
   
//         char *identifier = strtok(line, " ");
//         if (identifier) {
//             if (strcmp(identifier, "o") == 0) {
//                 char *name = strtok(NULL, " ");
//                 removeNewline(name);
//                 renameObject(object, name);
//                 continue;
//             }
//             if (strcmp(identifier, "v") == 0) {
//                 vec3 *vertex = createVertex(object);

//                 char *x = strtok(NULL, " ");
//                 char *y = strtok(NULL, " ");
//                 char *z = strtok(NULL, " ");

//                 vec3 pos = (vec3){atof(x), atof(y), atof(z)};

//                 positionVertex(vertex, pos);
//                 continue;
//             }
//             if (strcmp(identifier, "f") == 0) {
//                 face *face = createFace(object);

//                 char *a = strtok(NULL, " ");
//                 char *b = strtok(NULL, " ");
//                 char *c = strtok(NULL, " ");

//                 fillFace(face, atoi(a), atoi(b), atoi(c));
//                 continue;
//             }
//         }
//     }
//     for (int i = 0; i < object->mesh.n_faces; i++) {
//         vec3 a = object->mesh.verticies[object->mesh.faces[i].a];
//         vec3 b = object->mesh.verticies[object->mesh.faces[i].b];
//         vec3 c = object->mesh.verticies[object->mesh.faces[i].c];

//         object->mesh.faces[i].normal = normVec(crossProduct(subVec(c, a), subVec(b, a)));
//     }
// }
void importObject(scene_t *scene) {
    /* system("clear");
    printf("enter directory: ");

    char dirPath[256];
    DIR *dir;

    do {
        fgets(dirPath, sizeof(dirPath), stdin);
        removeNewline(dirPath);
        dir = opendir(dirPath);

        if (!dir) {
            printf("no such directory: %s\n", dirPath);
        }
    } while (!dir);

    int n_files = 0;
    char **files = NULL;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_REG) {
            continue;
        }
        n_files++;
        files = realloc(files, sizeof(char *) * n_files);

        files[n_files - 1] = strdup(entry->d_name);
    }

    closedir(dir);

    int selection = selectFromList("lol", files, n_files);

    char filePath[512];
    snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, files[selection]);

    FILE *file = fopen(filePath, "r");

    obj *object = createObject(scene);

    importFromObj(object, file);
    moveObject(object, (vec3){0, 0, 0});
    scaleObject(object, (vec3){1, 1, 1}); */
}
// void printObjectInfo(obj *object) {
//     printf("| object name: \"%s\"\n", object->name);
//     printf("| vertices: %d\n", object->mesh.n_vertices);
//     for (int i = 0; i < object->mesh.n_vertices; i++) {
//     renameScene(scene);
//     moveCamera(&scene->camera, (vec3){0, 0, -2});
//     for (int i = 0; i < scene->n_objects; i++) {
//         free(scene->objects[i].mesh.verticies);
//         free(scene->objects[i].mesh.faces);
//     }
//     free(scene->objects);
//     scene->n_objects = 0;
//     return;    return;
// }
// void renameScene(scene *scene) {
//     printf("Enter scene name: ");
//     char sceneName[64];

//     if (fgets(sceneName, sizeof(sceneName), stdin) == NULL) {
//         printf("Scene was not renamed\n");
//         return;
//     }

//     removeNewline(sceneName);

//     if (strlen(sceneName) == 0) {
//         snprintf(sceneName, sizeof(sceneName), "default");
//     }

//     snprintf(scene->name, sizeof(scene->name), "%s", sceneName);
//     printf("Scene named: %s", scene->name);
//     getchar();
//     return;
// }
// void clearScene(scene *scene) {
//      renameScene(scene);
//     moveCamera(&scene->camera, (vec3){0, 0, -2});
//     for (int i = 0; i < scene->n_objects; i++) {
//         free(scene->objects[i].mesh.verticies);
//         free(scene->objects[i].mesh.faces);
//     }
//     free(scene->objects);
//     scene->n_objects = 0;
//     return; 
// }

