#include <vector>
#include <GL/glew.h>
#include "Rendering.hpp"
#include "Model.hpp"
#include "Vector2.hpp"
#include "TextureTypes.hpp"
#include "MeshTypes.hpp"

using std::vector, std::string;

GeometryMesh CreateCube();

RenderingSystem::RenderingSystem() {
    GeometryMesh obj = CreateCube();
    geometry_objects.insert({MeshTypes::Cube, obj});

    Texture troll_texture("water.png");
    geometry_textures.insert({TextureTypes::Troll, troll_texture});
}

RenderingSystem::~RenderingSystem() {
    for (auto mesh_pair : geometry_objects) {
        GeometryMesh mesh = mesh_pair.second;
        mesh.Destroy();
    }
    geometry_objects.clear();

    for (auto texture_pair : geometry_textures) {
        Texture texture = texture_pair.second;
        texture.Destroy();
    }
    geometry_textures.clear();

    for (auto shader : shaders_programs)
        shader.Destroy();

    shaders_programs.clear();
}

void RenderingSystem::CreateShaders() {
    vector<ShaderInformation> shader_infos {
        {"vertex.glsl", GL_VERTEX_SHADER},
        {"fragment.glsl", GL_FRAGMENT_SHADER}
    };

    GLuint program_id = CreateShaderProgram(shader_infos);
    shaders_programs.emplace_back(program_id);

    shader_infos.clear();
}

GeometryMesh CreateCube() {
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
        {0.0, 1.0, -1.0},
        {1.0,  1.0, -1.0},
        {1.0, 1.0, -1.0},
        {1.0,  0.0, -1.0},
        {0.0, 0.0, -1.0},

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

        {0.0, 0.0, -1.0},
        {0.0, 0.0, -1.0},
        {0.0, 0.0, -1.0},
        {0.0, 0.0, -1.0},
        {0.0, 0.0, -1.0},
        {0.0, 0.0, -1.0},

        {-1.0, 0.0, 0.0},
        {-1.0,  0.0, 0.0},
        {-1.0, 0.0, 0.0},
        {-1.0, 0.0, 0.0},
        {-1.0,  0.0, 0.0},
        {-1.0, 0.0, 0.0},

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

    auto *textures = new Vector2F[36] {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},

        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},

        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},

        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},

        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},

        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},
    };

    GeometryData geometry = {
        36,
        vertices,
        normals,
        textures
    };

    GeometryMesh object(geometry);
    return object;
}

GLuint RenderingSystem::CreateVertexArrayObject() {
    GLuint vao = 0u;
    glGenVertexArrays(1, &vao);
    return vao;
}

GLuint RenderingSystem::CreateVertexBufferObject() {
    GLuint vbo = 0u;
    glGenBuffers(1, &vbo);
    return vbo;
}

void SetVector3fUniformData(GLuint program_id, const string& uniform_name, Vector3F &data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name.c_str());
    glUseProgram(program_id);
    glUniform3f(id, data_reference.GetX(), data_reference.GetY(), data_reference.GetZ());
    glUseProgram(0);
}

void SetMatrix4fUniformData(GLuint program_id, const string& uniform_name, Matrix4F &data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name.c_str());
    glUseProgram(program_id);
    glProgramUniformMatrix4fv(program_id, id, 1, 0, data_reference.GetElements());
    glUseProgram(0);
}