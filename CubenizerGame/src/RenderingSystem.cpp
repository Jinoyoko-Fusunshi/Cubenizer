#include <vector>
#include <GL/glew.h>
#include <Vector2.hpp>
#include "RenderingSystem.hpp"
#include "Cube.hpp"
#include "TextureTypes.hpp"
#include "MeshTypes.hpp"
#include "MeshBuilder.hpp"
#include "MeshFactory.hpp"

using std::vector, std::string;

Mesh CreateCube();

RenderingSystem::~RenderingSystem() {
    for (auto mesh_pair : meshes) {
        Mesh mesh = mesh_pair.second;
        mesh.Destroy();
    }
    meshes.clear();

    for (auto texture_pair : textures) {
        Texture texture = texture_pair.second;
        texture.Destroy();
    }
    textures.clear();

    for (auto shader_pair : shaders_programs) {
        ShaderProgram shader = shader_pair.second;
        shader.Destroy();
    }
    shaders_programs.clear();
}

void RenderingSystem::CreateShaders() {
    vector<ShaderInformation> shader_infos {
        {"vertex.glsl", GL_VERTEX_SHADER},
        {"fragment.glsl", GL_FRAGMENT_SHADER}
    };

    GLuint program_id = CreateShaderProgram(shader_infos);
    shaders_programs.insert({ShaderTypes::BasicCubeShader, ShaderProgram(program_id)});
    shader_infos.clear();
}

Mesh CreateCube() {
    Vector3D start_point(0.0, 0.0, 0.0);
    Vector3D width = Vector3D::XUnitVector3() * Cube::ModelWidth;
    Vector3D height = Vector3D::YUnitVector3() * Cube::ModelWidth;
    Vector3D depth = Vector3D::ZUnitVector3() * Cube::ModelWidth;

    MeshBuilder builder {};
    builder
        .AddVertex(start_point).AddVertex(start_point + height)
        .AddVertex(start_point + width + height).AddVertex(start_point + width)
        .AddVertex(start_point + width).AddVertex(start_point + width + height)
        .AddVertex(start_point + width + height - depth).AddVertex(start_point + width - depth)
        .AddVertex(start_point - depth).AddVertex(start_point + height - depth)
        .AddVertex(start_point + height).AddVertex(start_point)
        .AddVertex(start_point + width - depth).AddVertex(start_point + width + height - depth)
        .AddVertex(start_point + height - depth).AddVertex(start_point - depth)
        .AddVertex(start_point + height).AddVertex(start_point + height - depth)
        .AddVertex(start_point + width + height - depth).AddVertex(start_point + width + height)
        .AddVertex(start_point - depth).AddVertex(start_point)
        .AddVertex(start_point + width).AddVertex(start_point + width - depth)
        .AddNormal(Vector3D(0.0, 0.0, 1.0)).AddNormal(Vector3D(0.0, 0.0, 1.0)).AddNormal(Vector3D(0.0, 0.0, 1.0)).AddNormal(Vector3D(0.0, 0.0, 1.0))
        .AddNormal(Vector3D(1.0, 0.0, 0.0)).AddNormal(Vector3D(1.0, 0.0, 0.0)).AddNormal(Vector3D(1.0, 0.0, 0.0)).AddNormal(Vector3D(1.0, 0.0, 0.0))
        .AddNormal(Vector3D(-1.0, 0.0, 0.0)).AddNormal(Vector3D(-1.0, 0.0, 0.0)).AddNormal(Vector3D(-1.0, 0.0, 0.0)).AddNormal(Vector3D(-1.0, 0.0, 0.0))
        .AddNormal(Vector3D(0.0, 0.0, -1.0)).AddNormal(Vector3D(0.0, 0.0, -1.0)).AddNormal(Vector3D(0.0, 0.0, -1.0)).AddNormal(Vector3D(0.0, 0.0, -1.0))
        .AddNormal(Vector3D(0.0, 1.0, 0.0)).AddNormal(Vector3D(0.0, 1.0, 0.0)).AddNormal(Vector3D(0.0, 1.0, 0.0)).AddNormal(Vector3D(0.0, 1.0, 0.0))
        .AddNormal(Vector3D(0.0, -1.0, 0.0)).AddNormal(Vector3D(0.0, -1.0, 0.0)).AddNormal(Vector3D(0.0, -1.0, 0.0)).AddNormal(Vector3D(0.0, -1.0, 0.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddIndex(0).AddIndex(1).AddIndex(2).AddIndex(2).AddIndex(3).AddIndex(0)
        .AddIndex(4).AddIndex(5).AddIndex(6).AddIndex(6).AddIndex(7).AddIndex(4)
        .AddIndex(8).AddIndex(9).AddIndex(10).AddIndex(10).AddIndex(11).AddIndex(8)
        .AddIndex(12).AddIndex(13).AddIndex(14).AddIndex(14).AddIndex(15).AddIndex(12)
        .AddIndex(16).AddIndex(17).AddIndex(18).AddIndex(18).AddIndex(19).AddIndex(16)
        .AddIndex(20).AddIndex(21).AddIndex(22).AddIndex(22).AddIndex(23).AddIndex(20);
    builder.Build();

    return Mesh(builder.GetBuildResult());
}

void RenderingSystem::CreateGeometries() {
    meshes.insert({MeshTypes::CubeMesh, MeshFactory::CreateCubeMesh(Cube::ModelWidth, Cube::ModelWidth, Cube::ModelWidth)});
}

void RenderingSystem::CreateTextures() {
    textures.insert({TextureTypes::Water, Texture("water.png")});
}
