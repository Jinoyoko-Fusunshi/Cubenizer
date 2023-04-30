#include <malloc.h>
#include "GeometryObject.h"

void ConvertToVertexData(GeometryData *geometry_reference, VertexData *vertex_data_reference);

GeometryObject* CreateGeometryObject(GeometryData *geometry_reference) {
    VertexData vertex_data[geometry_reference->vertices_length];
    GeometryObject *geometry = (GeometryObject*)malloc(sizeof(GeometryObject));
    geometry->vao_id = CreateVertexArrayObject();
    geometry->vbo_id = CreateVertexBufferObject();
    geometry->vertices_length = geometry_reference->vertices_length;

    ConvertToVertexData(geometry_reference, vertex_data);

    glBindVertexArray(geometry->vao_id);
    glBindBuffer(GL_ARRAY_BUFFER, geometry->vbo_id);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(VertexData) * geometry_reference->vertices_length),
                 vertex_data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)sizeof(Vector3f));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    free(geometry_reference->vertices);
    free(geometry_reference->normals);

    return geometry;
}

void ConvertToVertexData(GeometryData *geometry_reference, VertexData *vertex_data_reference) {
    uint32_t normal_count = geometry_reference->vertices_length;

    for (uint32_t i = 0; i < normal_count; i++) {
        VertexData data_set = {geometry_reference->vertices[i], geometry_reference->normals[i]};
        vertex_data_reference[i] = data_set;
    }
}
