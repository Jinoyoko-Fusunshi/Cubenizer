#include "BufferFactory.hpp"

GLuint BufferFactory::CreateVertexArrayObject() {
    GLuint vertex_array_object_id = 0;
    glGenVertexArrays(1, &vertex_array_object_id);
    return vertex_array_object_id;
}

GLuint BufferFactory::CreateVertexBufferObject() {
    GLuint vertex_buffer_object_id = 0;
    glGenBuffers(1, &vertex_buffer_object_id);
    return vertex_buffer_object_id;
}

GLuint BufferFactory::CreateElementBuffer() {
    GLuint element_buffer_object_id = 0;
    glGenBuffers(1, &element_buffer_object_id);
    return element_buffer_object_id;
}