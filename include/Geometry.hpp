#pragma once

#include <stdint-gcc.h>
#include "Vector3.hpp"
#include "Vector2.hpp"

struct GeometryData {
    uint32_t vertices_length;
    uint32_t indices_length;
    Vector3F *vertices;
    Vector3F *normals;
    Vector2F *textures;
    GLuint *indices;
};
