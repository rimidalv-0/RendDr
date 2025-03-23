#ifndef VECTORS_H
#define VECTORS_H

/// @brief vector math operations

/// @brief vec2 type with xy int coordinates
typedef struct
{
    int x;
    int y;
} vec2;

/// @brief vec3 type with xyz float coordinates
typedef struct
{
    float x;
    float y;
    float z;
} vec3;

/// @param v1 first vector
/// @param v2 second vector
/// @return v1 + v2
vec2 addVec2(vec2 v1, vec2 v2);

/// @param v1 first vector
/// @param v2 second vector
/// @return v1 + v2
vec3 addVec(vec3 v1, vec3 v2);

/// @param v1 first vector
/// @param v2 second vector
/// @return v1 - v2
vec2 subVec2(vec2 v1, vec2 v2);

/// @param v1 first vector
/// @param v2 second vector
/// @return v1 - v2
vec3 subVec(vec3 v1, vec3 v2);

/// @brief scales a 3D vector by a flaot value
/// @param v1 vector to scale
/// @param scale scale factor
/// @return v1 * scale
vec3 scaleVec(vec3 v1, float scale);

/// @brief multiplies the coresponding coordinates of two vector
/// @param v1 first vector
/// @param v2 second vector
/// @return x1*x2, y1*y2, z1*z2
vec3 multVec(vec3 v1, vec3 v2);

/// @brief calculate the magnitude of the vector
/// @param v1 vector to get the length from
/// @return length of the vector
float lengthVec(vec3 v1);

/// @param v1 first vector 
/// @param v2 second vector
/// @return sin(angle between the vectors)
float dotProduct(vec3 v1, vec3 v2);

/// @param v1 first vector
/// @param v2 second vector
/// @return cross vector 
vec3 crossProduct(vec3 v1, vec3 v2);

/// @param v1 vector to normalize
/// @return v1 scaled to magnitude 1 unit
vec3 normVec(vec3 v1);

/// @brief reflects a vector 
/// @param v1 vector to reflect
/// @param norm normal vector to reflect from
/// @return the vector with same magnitude with reflected direction
vec3 reflectVec(vec3 v1, vec3 norm);

#endif