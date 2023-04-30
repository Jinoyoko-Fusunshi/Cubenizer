#include <malloc.h>
#include "Rendering.h"
#include "Model.h"

GeometryObject* CreateCube(RenderingSystem *render_system_reference);

RenderingSystem CreateRenderingSystem() {
    RenderingSystem render_system = {};
    InitList(&render_system.shaders);
    InitSet(&render_system.geometry_objects);

    GeometryObject *cube = CreateCube(&render_system);
    AddPair(&render_system.geometry_objects, 0, (void*)cube);

    return render_system;
}

GeometryObject* CreateCube(RenderingSystem *render_system_reference) {
    Vector3f vertices[36] = {
        {0.0f, 0.0f, 0.0f},
        {0.0f,  1.0f, 0.0f},
        {1.0f, 1.0f, 0.0f},
        {1.0f, 1.0f, 0.0f},
        {1.0f,  0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},

        {1.0f, 0.0f, 0.0f},
        {1.0f,  1.0f, 0.0f},
        {1.0f, 1.0f, -1.0f},
        {1.0f, 1.0f, -1.0f},
        {1.0f,  0.0f, -1.0f},
        {1.0f, 0.0f, 0.0f},

        {0.0f, 0.0f, 0.0f},
        {0.0f,  1.0f, 0.0f},
        {0.0f, 1.0f, -1.0f},
        {0.0f, 1.0f, -1.0f},
        {0.0f,  0.0f, -1.0f},
        {0.0f, 0.0f, 0.0f},

        {0.0f, 0.0f, -1.0f},
        {1.0f, 1.0f, -1.0f},
        {0.0f,  1.0f, -1.0f},
        {0.0f, 0.0f, -1.0f},
        {1.0f,  0.0f, -1.0f},
        {1.0f, 1.0f, -1.0f},

        {0.0f, 1.0f, 0.0f},
        {0.0f,  1.0f, -1.0f},
        {1.0f, 1.0f, -1.0f},
        {1.0f, 1.0f, -1.0f},
        {1.0f,  1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},

        {0.0f, 0.0f, 0.0f},
        {0.0f,  0.0f, -1.0f},
        {1.0f, 0.0f, -1.0f},
        {1.0f, 0.0f, -1.0f},
        {1.0f,  0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},
    };
    Vector3f normals[36] = {
        {0.0f, 0.0f, 1.0f},
        {0.0f,  0.0f, 1.0f},
        {0.0f, 0.0f, 1.0f},
        {0.0f, 0.0f, 1.0f},
        {0.0f,  0.0f, 1.0f},
        {0.0f, 0.0f, 1.0f},

        {1.0f, 0.0f, 0.0f},
        {1.0f,  0.0f, 0.0f},
        {1.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 0.0f},
        {1.0f,  0.0f, 0.0f},
        {1.0f, 0.0f, 0.0f},

        {-1.0f, 0.0f, 0.0f},
        {-1.0f,  0.0f, 0.0f},
        {-1.0f, 0.0f, 0.0f},
        {-1.0f, 0.0f, 0.0f},
        {-1.0f,  0.0f, 0.0f},
        {-1.0f, 0.0f, 0.0f},

        {0.0f, 0.0f, -1.0f},
        {0.0f,  0.0f, -1.0f},
        {0.0f, 0.0f, -1.0f},
        {0.0f, 0.0f, -1.0f},
        {0.0f,  0.0f, -1.0f},
        {0.0f, 0.0f, -1.0f},

        {0.0f, 1.0f, 0.0f},
        {0.0f,  1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f,  1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},

        {0.0f, -1.0f, 0.0f},
        {0.0f,  -1.0f, 0.0f},
        {0.0f, -1.0f, 0.0f},
        {0.0f, -1.0f, 0.0f},
        {0.0f,  -1.0f, 0.0f},
        {0.0f, -1.0f, 0.0f},
    };

    GeometryData geometry = {36, AllocateVectors(vertices, 36), AllocateVectors(normals, 36)};
    return CreateGeometryObject(&geometry);
}

Vector3f* AllocateVectors(Vector3f *vectors_reference, uint32_t vectors_length) {
    Vector3f *vertices = malloc(vectors_length * sizeof(Vector3f));

    for (uint32_t i = 0; i < vectors_length; i++)
        vertices[i] = vectors_reference[i];

    return vertices;
}

GLuint CreateVertexArrayObject() {
    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    return vao;
}

GLuint CreateVertexBufferObject() {
    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    return vbo;
}

void SetVector3fUniformData(GLuint program_id, const char* uniform_name, Vector3f *data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name);
    glUseProgram(program_id);
    glUniform3f(id, data_reference->x, data_reference->y, data_reference->z);
    glUseProgram(0);
}

void SetMatrix4fUniformData(GLuint program_id, const char* uniform_name, Matrix4f *data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name);
    glUseProgram(program_id);
    glProgramUniformMatrix4fv(program_id, id, 1, 0, data_reference->elements);
    glUseProgram(0);
}