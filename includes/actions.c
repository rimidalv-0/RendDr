#include "types.h"

obj *createObject(scene *scene) {
    scene->n_objects++;
    scene->objects = realloc(scene->objects, sizeof(obj) * scene->n_objects);

    return &scene->objects[scene->n_objects - 1];
}

void changeObjectColor(obj *object, vec3 col) {
    object->mat = col;
}