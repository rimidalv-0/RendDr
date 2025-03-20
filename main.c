#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "includes/symbols.h"
#include "includes/vectors.h"
#include "includes/types.h"
#include "includes/helper.h"
#include "includes/infoLine.h"
#include "includes/actions.h"
#include "includes/menu.h"

#define charRatio 14.0 / 36.0
#define samples 10
#define reflections 10

/* float rayCast(vec3 start, vec3 dir, float power, int depth, obj *objects, int n_objects) {
    if (depth > reflections || power <= 0) {
        return 0;
    }

    float closestHit = __FLT_MAX__;
    obj *closestObject = NULL;
    vec3 hitPoint, normal;

    for (int i = 0; i < n_objects; i++) {
        obj object = objects[i];

        for (int j = 0; j < object.mesh.n_faces; j++) {
            face face = object.mesh.faces[j];

            vec3 A = addVec(multVec(object.mesh.verticies[face.a - 1], object.scale), object.pos);
            vec3 B = addVec(multVec(object.mesh.verticies[face.b - 1], object.scale), object.pos);
            vec3 C = addVec(multVec(object.mesh.verticies[face.c - 1], object.scale), object.pos);

            vec3 AB = subVec(B, A);
            vec3 AC = subVec(C, A);
            vec3 NORM = object.mesh.faces->normal;

            if (dotProduct(dir, NORM) >= 0) continue;

            vec3 AO = subVec(start, A);
            vec3 P = crossProduct(dir, AC);
            float det = dotProduct(AB, P);
            float invDet = 1.0 / det;
            float u = dotProduct(AO, P) * invDet;

            if (u < 0.0 || u > 1.0) continue;

            vec3 Q = crossProduct(AO, AB);
            float v = dotProduct(dir, Q) * invDet;
            if (v < 0.0 || u + v > 1.0) continue;

            float t = dotProduct(AC, Q) * invDet;

            if (t > 0 && t < closestHit) {
                closestHit = t;
                closestObject = &object;
                hitPoint = addVec(start, scaleVec(dir, t));
            }
        }
    }

    if (!closestObject) return 0;

    float hitColor = closestObject->mat.x;
    float hitLight = closestObject->mat.z;
    float hitDifusion = closestObject->mat.y;

    int sampleCount = 1 + (int)(hitDifusion * samples);

    float light = 0;

    for (int i = 0; i < sampleCount; i++) {
        vec3 bounceDir = reflect(dir, normal);

        float bouncedLight = rayCast(hitPoint, bounceDir, power * hitColor, depth + 1, objects, n_objects);
        light += bouncedLight;
    }

    light = light / (float)sampleCount;

    return light * hitColor + hitLight;
}

float drawPixel(float x, float y, cam camera, obj *objects, int n_objects) {
    vec3 dir = (vec3){x, y, camera.fov};
    return rayCast(camera.pos, normVec(dir), 1, 0, objects, n_objects);
}

void renderScene(scene scene) {
    int n_objects = scene.n_objects;
    char gradient[] = " `'.,-~:;=!^+*>i{1(|/flrxnuczmwao#WM&8B@$";
    int gradientSize = sizeof(gradient) / sizeof(char) - 2;

    for (int y = 0; y < windowHeight; y++) {     // for every line
        for (int x = 0; x < windowWidth; x++) {  // for every pixel

            // map the x y values
            float fx = ((((float)x / windowWidth) - 0.5) * 2) * (windowWidth / windowHeight) * charRatio;
            float fy = (((float)y / windowHeight) - 0.5) * 2;
            float randValue = (float)rand() / RAND_MAX;

            // get the pixel value
            float pixelValue = drawPixel(fx, fy, scene.camera, scene.objects, n_objects);

            // if pixel too dark clamp at 0
            if (pixelValue <= 0.0) {
                pixelValue = 0.0;
            }
            // if pixel too bright clamp at 1
            if (pixelValue >= 1.0) {
                pixelValue = 1.0;
            }

            // map the pixel value to the gradient
            pixelValue = pixelValue * gradientSize;

            // get the random gradient size
            int gradientValue;
            if (pixelValue - floor(pixelValue) > randValue) {
                gradientValue = (int)ceil(pixelValue);
            } else {
                gradientValue = (int)floor(pixelValue);
            }
            // pritn the gradient value for pixel
            fprintf(stdout, "%c", gradient[gradientValue]);
        }
        printf("\n");
    }
}
 */

 int main() {
    vec2 windowSize = {100,50};
    int windowWidth = 100;
    int windowHeight = 50;
    vec2 infoLinePos = {0, windowHeight - 3};


    scene scene;
    drawBuffer(NULL,windowWidth,windowHeight);
    drawInfoLine(infoLinePos, (vec2){windowSize.x, 3});

    return 0;
}
