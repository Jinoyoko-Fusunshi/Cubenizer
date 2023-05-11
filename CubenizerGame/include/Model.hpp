#pragma once

#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "ShaderProgram.hpp"
#include "GeometryMesh.hpp"
#include "Texture.hpp"
#include "TextureTypes.hpp"

class Model {
private:
    Vector3F position {};
    Vector3F color {};
    Texture texture {};
    GeometryMesh geometry {};
    ShaderProgram shader {};

public:
    explicit Model(Vector3F position, GeometryMesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference);
    ~Model() = default;

    void UpdateModelMatrix();
    void UpdateViewMatrix(const Matrix4F &view_matrix_reference);
    void UpdateProjectionMatrix(const Matrix4F &projection_matrix_reference);
    void UpdateColor();
    void UpdateFaces(const int* face_ids, int face_length);
    void DrawModel();

    Vector3F& GetColor() { return color; }
    Matrix4F GetModelMatrix();
};