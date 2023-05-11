#pragma once

#include <GL/glew.h>
#include "Geometry.hpp"

class GeometryMesh {
private:
    uint32_t indices_length = 0;
    GLuint vao_id = 0u;
    GLuint vbo_id = 0u;
    GLuint ebo_id = 0u;

public:
    GeometryMesh() = default;
    explicit GeometryMesh(GeometryData &geometry_data);
    ~GeometryMesh() = default;

    void Destroy();

    [[nodiscard]] GLuint GetVAO() const { return vao_id; }
    [[nodiscard]] GLuint GetVBO() const { return vbo_id; }
    [[nodiscard]] GLuint GetEBO() const { return ebo_id; }
    [[nodiscard]] uint32_t GetIndicesSize() const  { return indices_length; }
};