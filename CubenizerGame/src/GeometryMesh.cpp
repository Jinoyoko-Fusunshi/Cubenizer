#include "GeometryMesh.hpp"
#include "Rendering.hpp"
#include "VertexData.hpp"

void ConvertToVertexData(GeometryData &geometry_reference, VertexData *vertex_data_reference);

GeometryMesh::GeometryMesh(GeometryData &geometry_data) {
    vao_id = RenderingSystem::CreateVertexArrayObject();
    vbo_id = RenderingSystem::CreateVertexBufferObject();
    ebo_id = RenderingSystem::CreateElementBuffer();
    indices_length = geometry_data.indices_length;

    VertexData vertex_data[geometry_data.indices_length];
    ConvertToVertexData(geometry_data, vertex_data);
    glBindVertexArray(vao_id);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(VertexData) * geometry_data.vertices_length),
        vertex_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(sizeof(GLuint) * geometry_data.indices_length),
         geometry_data.indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)nullptr);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)sizeof(Vector3F));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(2 * sizeof(Vector3F)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    delete[] geometry_data.vertices;
    delete[] geometry_data.normals;
    delete[] geometry_data.indices;
}

void GeometryMesh::Destroy() {
    glDeleteBuffers(1, &vbo_id);
    glDeleteVertexArrays(1, &vao_id);
}

void ConvertToVertexData(GeometryData &geometry_reference, VertexData *vertex_data_reference) {
    uint32_t normal_count = geometry_reference.indices_length;

    for (uint32_t i = 0u; i < normal_count; i++) {
        VertexData data_set = { geometry_reference.vertices[i], geometry_reference.normals[i], geometry_reference.textures[i]};
        vertex_data_reference[i] = data_set;
    }
}
