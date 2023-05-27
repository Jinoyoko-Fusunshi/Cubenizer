#pragma once

#include <vector>
#include <map>
#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "MeshData.hpp"
#include "ShaderProgram.hpp"
#include "ShaderUnit.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "MeshTypes.hpp"
#include "TextureTypes.hpp"

class RenderingSystem {
private:
    std::vector<ShaderProgram> shaders_programs;
    std::map<uint32_t, Mesh> meshes;
    std::map<uint32_t, Texture> geometry_textures;

public:
    RenderingSystem() = default;
    ~RenderingSystem();
    void CreateGeometries();
    void CreateTextures();
    void CreateShaders();

    ShaderProgram& GetShadersReference(const uint32_t index) { return shaders_programs[index]; }
    [[nodiscard]] Mesh& GetMeshByType(const MeshTypes meshType) { return meshes[meshType]; }
    [[nodiscard]] Texture& GetTextureByType(const TextureTypes textureType) { return geometry_textures[textureType]; }

    static GLuint CreateVertexArrayObject();
    static GLuint CreateVertexBufferObject();
    static GLuint CreateElementBuffer();
};