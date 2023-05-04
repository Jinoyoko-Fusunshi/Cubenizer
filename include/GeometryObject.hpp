#pragma once

#include <GL/glew.h>
#include "Geometry.hpp"

enum GeometryObjectIndices {
    Cube = 0
};

class GeometryObject {
private:
    GLuint vao_id = 0;
    GLuint vbo_id = 0;
    uint32_t vertices_length = 0;

public:
    GeometryObject() = default;
    explicit GeometryObject(GeometryData &geometry_data);
    ~GeometryObject() = default;

    uint32_t GetVerticesSize() { return vertices_length; }
    GLuint GetVAO() { return vao_id; }
    GLuint GetVBO() { return vbo_id; }
};