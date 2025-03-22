#ifndef VECTORS_H
#define VECTORS_H



typedef struct
{
    int x;
    int y;
} vec2;
typedef struct
{
    float x;
    float y;
    float z;
} vec3;
vec3 addVec(vec3 v1, vec3 v2);
vec2 subVec2(vec2 a, vec2 b);
vec3 subVec(vec3 v1, vec3 v2);
vec3 scaleVec(vec3 v1, float scale);
vec3 multVec(vec3 v1, vec3 v2);
float lengthVec(vec3 v1);
float dotProduct(vec3 v1, vec3 v2);
vec3 crossProduct(vec3 v1, vec3 v2);
vec3 normVec(vec3 v1);
vec3 reflectVec(vec3 v1, vec3 norm);

#endif