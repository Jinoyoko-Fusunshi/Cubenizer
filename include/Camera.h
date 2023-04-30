#pragma once

#include "Vector.h"

typedef struct {
    Vector3f position;
} Camera;


void TranslateCamera(Camera *camera_reference, Vector3f translation_vector);