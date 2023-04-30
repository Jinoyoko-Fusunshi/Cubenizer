#pragma once

#include <stdint-gcc.h>
#include "Vector.h"

typedef struct GeometryData {
    uint32_t vertices_length;
    Vector3f *vertices;
    Vector3f *normals;
} GeometryData;
