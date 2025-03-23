#ifndef TYPES_H
#define TYPES_H

#include "vectors.h"

typedef struct {
    int a;
    int b;
    int c;
    vec3 normal;
} face_t;
typedef struct {
    int n_vertices;
    vec3 *verticies;
    int n_faces;
    face_t *faces;
} mesh_t;
typedef struct {
    char name[64];
    vec3 pos;
    vec3 scale;
    vec3 mat;
    mesh_t mesh;
} object_t;
typedef struct {
    vec3 pos;
    float fov;
} camera_t;
typedef struct {
    char *name;
    int n_objects;
    object_t *objects;
    camera_t camera;
    float **buffer;
} scene_t;

#endif