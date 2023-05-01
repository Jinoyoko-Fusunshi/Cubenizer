#pragma once

#include "Vector.hpp"

typedef struct {
    Vector3f position;
} Camera;


void TranslateCamera(Camera *camera_reference, Vector3f translation_vector);