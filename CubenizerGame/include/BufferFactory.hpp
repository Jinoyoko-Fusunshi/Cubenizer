#pragma once

#include <GL/glew.h>

class BufferFactory {
public:
    static GLuint CreateVertexArrayObject();
    static GLuint CreateVertexBufferObject();
    static GLuint CreateElementBuffer();
};