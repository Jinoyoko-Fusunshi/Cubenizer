#include <vector>
#include <GL/glew.h>
#include "Rendering.hpp"
#include "Model.hpp"

using std::vector;

GeometryObject CreateCube();

RenderingSystem::RenderingSystem() {
    GeometryObject obj = CreateCube();

    geometry_objects.insert({0, obj});
}

void RenderingSystem::CreateShaders() {
    vector<ShaderInformation> shader_infos {
        {"vertex.glsl", GL_VERTEX_SHADER},
        {"fragment.glsl", GL_FRAGMENT_SHADER}
    };

    GLuint program_id = CreateShaderProgram(shader_infos);
    shaders_programs.emplace_back(program_id);
}

GeometryObject CreateCube() {
    auto *vertices = new Vector3F[36] {
        {0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {1.0, 1.0, 0.0},
        {1.0, 1.0, 0.0},
        {1.0,  0.0, 0.0},
        {0.0, 0.0, 0.0f},

        {1.0, 0.0, 0.0},
        {1.0,  1.0, 0.0},
        {1.0, 1.0, -1.0},
        {1.0, 1.0, -1.0},
        {1.0,  0.0, -1.0},
        {1.0, 0.0, 0.0},

        {0.0, 0.0, 0.0},
        {0.0,  1.0, 0.0},
        {0.0, 1.0, -1.0},
        {0.0, 1.0, -1.0},
        {0.0,  0.0, -1.0},
        {0.0, 0.0, 0.0},

        {0.0, 0.0, -1.0},
        {1.0, 1.0, -1.0},
        {0.0,  1.0, -1.0},
        {0.0, 0.0, -1.0},
        {1.0,  0.0, -1.0},
        {1.0, 1.0, -1.0},

        {0.0, 1.0, 0.0},
        {0.0,  1.0, -1.0},
        {1.0, 1.0, -1.0},
        {1.0, 1.0, -1.0},
        {1.0,  1.0, 0.0},
        {0.0, 1.0, 0.0},

        {0.0, 0.0, 0.0},
        {0.0,  0.0, -1.0},
        {1.0, 0.0, -1.0},
        {1.0, 0.0, -1.0},
        {1.0,  0.0, 0.0},
        {0.0, 0.0, 0.0},
    };

    auto *normals = new Vector3F[36] {
        {0.0, 0.0, 1.0},
        {0.0,  0.0, 1.0},
        {0.0, 0.0, 1.0},
        {0.0, 0.0, 1.0},
        {0.0,  0.0, 1.0},
        {0.0, 0.0, 1.0},

        {1.0, 0.0, 0.0},
        {1.0,  0.0, 0.0},
        {1.0, 0.0, 0.0},
        {1.0, 0.0, 0.0},
        {1.0,  0.0, 0.0},
        {1.0, 0.0, 0.0},

        {-1.0, 0.0, 0.0},
        {-1.0,  0.0, 0.0},
        {-1.0, 0.0, 0.0},
        {-1.0, 0.0, 0.0},
        {-1.0,  0.0, 0.0},
        {-1.0, 0.0, 0.0},

        {0.0, 0.0, -1.0},
        {0.0,  0.0, -1.0},
        {0.0, 0.0, -1.0},
        {0.0, 0.0, -1.0},
        {0.0,  0.0, -1.0},
        {0.0, 0.0, -1.0},

        {0.0, 1.0, 0.0},
        {0.0,  1.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0,  1.0, 0.0},
        {0.0, 1.0, 0.0},

        {0.0, -1.0, 0.0},
        {0.0,  -1.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, -1.0, 0.0},
    };

    GeometryData geometry = {36, vertices, normals};
    GeometryObject object(geometry);
    return object;
}

GLuint CreateVertexArrayObject() {
    GLuint vao = 0u;
    glGenVertexArrays(1, &vao);
    return vao;
}

GLuint CreateVertexBufferObject() {
    GLuint vbo = 0u;
    glGenBuffers(1, &vbo);
    return vbo;
}

void SetVector3fUniformData(GLuint program_id, const char* uniform_name, Vector3F &data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name);
    glUseProgram(program_id);
    glUniform3f(id, data_reference.GetX(), data_reference.GetY(), data_reference.GetZ());
    glUseProgram(0);
}

void SetMatrix4fUniformData(GLuint program_id, const char* uniform_name, Matrix4F &data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name);
    glUseProgram(program_id);
    glProgramUniformMatrix4fv(program_id, id, 1, 0, data_reference.GetElements());
    glUseProgram(0);
}