#ifndef ACTIONS_H
#define ACTIONS_H


#include "helper.h"
#include "types.h"
#include "vectors.h"

obj* createObject(scene* scene);
void changeObjectColor(obj* object, vec3 col);
void changeObjectColorWrapper(scene* scene);
void renameObject(obj* object, char name[64]);
void moveObject(obj* object, vec3 pos);
void moveObjectWrapper(scene* scene);
void scaleObject(obj* object, vec3 scale);
vec3* createVertex(obj* object);
void positionVertex(vec3* vertex, vec3 pos);
face* createFace(obj* object);
void fillFace(face* face, int a, int b, int c);
void importFromObj(obj* object, FILE* file);
void importObject(scene* scene);
void printObjectInfo(obj* object);
void moveCamera(cam* cam, vec3 pos);
void moveCameraWrapper(cam* cam);
void fovCamera(cam* cam, float a);
void fovCameraWrapper(cam* cam);
void renameScene(scene* scene);
void clearScene(scene* scene);

#endif