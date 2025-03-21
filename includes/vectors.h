#ifndef VECTORS_H
#define VECTORS_H

#include "types.h"

vec3 addVec(vec3 v1, vec3 v2);
vec3 subVec(vec3 v1, vec3 v2);
vec3 scaleVec(vec3 v1, float scale);
vec3 multVec(vec3 v1, vec3 v2);
float lengthVec(vec3 v1);
float dotProduct(vec3 v1, vec3 v2);
vec3 crossProduct(vec3 v1, vec3 v2);
vec3 normVec(vec3 v1);
vec3 reflectVec(vec3 v1, vec3 norm);

#endif