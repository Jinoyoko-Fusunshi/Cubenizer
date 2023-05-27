#pragma once

#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "TextureTypes.hpp"

class Model {
private:
    Vector3D position {};
    Texture texture {};
    Mesh geometry {};
    ShaderProgram shader {};

public:
    static constexpr double ModelWidth = 400.0;

    explicit Model(Vector3D position, Mesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference);
    ~Model() = default;

    void UpdateModelMatrix();
    void UpdateViewMatrix(const Matrix4F &view_matrix_reference);
    void UpdateProjectionMatrix(const Matrix4F &projection_matrix_reference);
    void UpdateColor();
    void UpdateFaces(const int* face_ids, int face_length);
    void DrawModel();

    Matrix4F GetModelMatrix();
};