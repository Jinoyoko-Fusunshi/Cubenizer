#pragma once

#include <GL/glew.h>
#include "MeshData.hpp"

class Mesh {
private:
    uint32_t indices_length = 0;
    GLuint vertex_array_id = 0u;
    GLuint vertex_buffer_id = 0u;
    GLuint element_buffer_id = 0u;

public:
    Mesh() = default;
    explicit Mesh(MeshData geometry_data);
    ~Mesh() = default;

    void Destroy();

    [[nodiscard]] GLuint GetVertexArrayID() const { return vertex_array_id; }
    [[nodiscard]] GLuint GetVertexBufferID() const { return vertex_buffer_id; }
    [[nodiscard]] GLuint GetElementBufferID() const { return element_buffer_id; }
    [[nodiscard]] uint32_t GetIndicesSize() const  { return indices_length; }
};