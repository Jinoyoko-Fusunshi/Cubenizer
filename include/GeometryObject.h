#pragma once

#include <GL/glew.h>
#include "Geometry.h"
#include "Rendering.h"

typedef struct GeometryObject {
    GLuint vao_id;
    GLuint vbo_id;
    uint32_t vertices_length;
} GeometryObject;

enum GeometryObjectIndices {
    Cube = 0
};

GeometryObject* CreateGeometryObject(GeometryData *geometry_reference);