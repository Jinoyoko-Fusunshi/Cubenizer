#pragma once

#include <vector>
#include <map>
#include "Vector3.hpp"
#include "Matrix.hpp"
#include "Geometry.hpp"
#include "ShaderProgram.hpp"
#include "ShaderUnit.hpp"
#include "GeometryMesh.hpp"
#include "Texture.hpp"
#include "MeshTypes.hpp"
#include "TextureTypes.hpp"

class RenderingSystem {
private:
    std::vector<ShaderProgram> shaders_programs;
    std::map<uint32_t, GeometryMesh> geometry_objects;
    std::map<uint32_t, Texture> geometry_textures;

public:
    RenderingSystem();
    ~RenderingSystem() = default;
    void CreateShaders();

    std::vector<ShaderProgram>& GetShadersReference() { return shaders_programs; }
    GeometryMesh& GetMeshByType(MeshTypes meshType) { return geometry_objects[meshType]; }
    Texture& GetTextureByType(TextureTypes textureType) { return geometry_textures[textureType]; }

    static GLuint CreateVertexArrayObject();
    static GLuint CreateVertexBufferObject();
};

GLuint CreateVertexArrayObject();
GLuint CreateVertexBufferObject();

void SetVector3fUniformData(GLuint program_id, const char* uniform_name, Vector3F &data_reference);
void SetMatrix4fUniformData(GLuint program_id, const char* uniform_name, Matrix4F &data_reference);