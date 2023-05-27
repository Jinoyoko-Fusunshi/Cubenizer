#pragma once

#include <vector>
#include <GL/glew.h>
#include <Vector3.hpp>
#include <Vector2.hpp>
#include "IBuilder.hpp"
#include "Mesh.hpp"

class MeshBuilder final : public IBuilder<MeshData> {
private:
    std::vector<Vector3D> vertices;
    std::vector<Vector3D> normals;
    std::vector<Vector2D> textures;
    std::vector<GLuint> indices;

    template<class V>
    MeshBuilder& AddEntry(std::vector<V> &collection_reference, V value);

public:
    MeshBuilder() : IBuilder() {}
    ~MeshBuilder() = default;

    void Build() override;

    MeshBuilder& AddVertex(Vector3D vertex);
    MeshBuilder& AddNormal(Vector3D normal);
    MeshBuilder& AddTextureCoordinate(Vector2D texture_coordinate);
    MeshBuilder& AddIndex(GLuint index);
};