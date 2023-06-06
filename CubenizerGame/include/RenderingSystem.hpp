#pragma once

#include <map>
#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "MeshData.hpp"
#include "ShaderUnit.hpp"
#include "ShaderTypes.hpp"
#include "MeshTypes.hpp"
#include "TextureTypes.hpp"
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

class RenderingSystem {
private:
    std::map<ShaderTypes, ShaderProgram> shaders_programs;
    std::map<MeshTypes, Mesh> meshes;
    std::map<TextureTypes, Texture> textures;

public:
    RenderingSystem() = default;
    ~RenderingSystem();
    void CreateGeometries();
    void CreateTextures();
    void CreateShaders();

    ShaderProgram& GetShadersReference(const ShaderTypes type) { return shaders_programs[type]; }
    [[nodiscard]] Mesh& GetMeshByType(const MeshTypes type) { return meshes[type]; }
    [[nodiscard]] Texture& GetTextureByType(const TextureTypes type) { return textures[type]; }
};