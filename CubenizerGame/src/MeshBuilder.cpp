#include "MeshBuilder.hpp"
#include "Exception.hpp"

using std::vector;

void MeshBuilder::Build() {
    current_state = BuildState::Finished;
    build_result = { vertices, normals, textures, indices };
}

MeshBuilder& MeshBuilder::AddVertex(Vector3D vertex) {
    return AddEntry<Vector3D>(vertices, vertex);
}

MeshBuilder& MeshBuilder::AddNormal(Vector3D normal) {
    return AddEntry<Vector3D>(normals, normal);
}

MeshBuilder& MeshBuilder::AddTextureCoordinate(Vector2D texture_coordinate) {
    return AddEntry<Vector2D>(textures, texture_coordinate);
}

MeshBuilder& MeshBuilder::AddIndex(GLuint index) {
    return AddEntry<GLuint>(indices, index);
}

template<class V>
MeshBuilder& MeshBuilder::AddEntry(vector<V> &collection_reference, V value) {
    if (current_state != BuildState::InProgress)
        throw Exception("Builder has already built the result.");
    
    collection_reference.emplace_back(value);

    return *this;
}