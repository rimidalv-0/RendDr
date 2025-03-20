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

vec3 addVec(vec3 a, vec3 b) {
    return (vec3){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z};
}

vec3 subVec(vec3 a, vec3 b) {
    return (vec3){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z};
}

vec3 scaleVec(vec3 a, float b) {
    return (vec3){
        a.x * b,
        a.y * b,
        a.z * b};
}

vec3 multVec(vec3 a, vec3 b) {
    return (vec3){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z};
}

float lengthVec(vec3 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

float dotProduct(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 crossProduct(vec3 a, vec3 b) {
    return (vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x};
}

vec3 normVec(vec3 a) {
    float len = lengthVec(a);
    if (len < 1e-6f) {
        return (vec3){0, 0, 0};
    }

    return scaleVec(a, 1.0f / len);
}

vec3 reflect(vec3 dir, vec3 normal) {

    return subVec(dir, scaleVec(normal, 2 * dotProduct(dir, normal)));
}

#endif