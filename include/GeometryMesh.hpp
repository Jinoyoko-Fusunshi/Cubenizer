#pragma once

#include <GL/glew.h>
#include "Geometry.hpp"

class GeometryMesh {
private:
    uint32_t vertices_length = 0;
    uint32_t indices_length = 0;
    GLuint vao_id = 0u;
    GLuint vbo_id = 0u;
    GLuint ebo_id = 0u;

public:
    GeometryMesh() = default;
    explicit GeometryMesh(GeometryData &geometry_data);
    ~GeometryMesh() = default;

    void Destroy();

    GLuint GetVAO() { return vao_id; }
    GLuint GetVBO() { return vbo_id; }
    GLuint GetEBO() { return ebo_id; }
    uint32_t GetVerticesSize() { return vertices_length; }
    uint32_t GetIndicesSize()  { return indices_length; }
};