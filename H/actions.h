#ifndef ACTIONS_H
#define ACTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "types.h"
#include "vectors.h"

typedef struct action {
    char* title;
    void (*fuction)();
} action_t;

extern action_t a_importObject;

object_t* createObject(scene_t* scene);
void changeObjectColor(object_t* object, vec3 col);
void changeObjectColorWrapper(scene_t* scene);
void renameObject(object_t* object, char name[64]);
void moveObject(object_t* object, vec3 pos);
void moveObjectWrapper(scene_t* scene);
void scaleObject(object_t* object, vec3 scale);
vec3* createVertex(object_t* object);
void positionVertex(vec3* vertex, vec3 pos);
face_t* createFace(object_t* object);
void fillFace(face_t* face, int a, int b, int c);
void importFromObj(object_t* object, FILE* file);
void printObjectInfo(object_t* object);
void moveCamera(camera_t* cam, vec3 pos);
void moveCameraWrapper(camera_t* cam);
void fovCamera(camera_t* cam, float a);
void fovCameraWrapper(camera_t* cam);
void renameScene(scene_t* scene);
void clearScene(scene_t* scene);

#endif