#ifndef TYPES_H
#define TYPES_H

#include "vectors.h"

typedef struct {
    int a;
    int b;
    int c;
    vec3 normal;
} face;
typedef struct {
    int n_vertices;
    vec3 *verticies;
    int n_faces;
    face *faces;
} mesh;
typedef struct {
    char name[64];
    vec3 pos;
    vec3 scale;
    vec3 mat;
    mesh mesh;
} obj;
typedef struct {
    vec3 pos;
    float fov;
} cam;
typedef struct {
    char *name;
    int n_objects;
    obj *objects;
    cam camera;
    float **buffer;
} scene;

#endif