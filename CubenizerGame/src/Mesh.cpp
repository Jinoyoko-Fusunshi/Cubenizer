#include <vector>
#include "Mesh.hpp"
#include "Rendering.hpp"
#include "ComposedVertex.hpp"
#include "Camera.hpp"

using std::vector;

vector<ComposedVertex> ConvertToVertexData(MeshData &geometry_reference);

Mesh::Mesh(MeshData geometry_reference) {
    vector<ComposedVertex> vertices = ConvertToVertexData(geometry_reference);
    vao_id = RenderingSystem::CreateVertexArrayObject();
    vbo_id = RenderingSystem::CreateVertexBufferObject();
    ebo_id = RenderingSystem::CreateElementBuffer();
    indices_length = (uint32_t)geometry_reference.indices.size();

    glBindVertexArray(vao_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(ComposedVertex) * geometry_reference.vertices.size()), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(sizeof(GLuint) * geometry_reference.indices.size()), geometry_reference.indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ComposedVertex), (void*)nullptr);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ComposedVertex), (void*)sizeof(Vector3F));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ComposedVertex), (void*)(2 * sizeof(Vector3F)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    geometry_reference.vertices.clear();
    geometry_reference.normals.clear();
    geometry_reference.indices.clear();
}

void Mesh::Destroy() {
    glDeleteBuffers(1, &vbo_id);
    glDeleteVertexArrays(1, &vao_id);
}

vector<ComposedVertex> ConvertToVertexData(MeshData &geometry_reference) {
    vector<ComposedVertex> vertices {};

    for (uint32_t i = 0; i < geometry_reference.indices.size(); i++) {
        Vector4F screen_space_vertex = Camera::GetScreenTransformationMatrix() * Vector4F(geometry_reference.vertices[i], 1.0);
        ComposedVertex vertex = { static_cast<Vector3F>(screen_space_vertex), (Vector3F)geometry_reference.normals[i], (Vector2F)geometry_reference.textures[i]};
        vertices.emplace_back(vertex);
    }

    return vertices;
}