#pragma once

#include <stdint-gcc.h>
#include "Vector.hpp"

struct GeometryData {
    uint32_t vertices_length;
    Vector3F *vertices;
    Vector3F *normals;
};
