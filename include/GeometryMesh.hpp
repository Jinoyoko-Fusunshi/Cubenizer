#pragma once

#include <GL/glew.h>
#include "Geometry.hpp"

class GeometryMesh {
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