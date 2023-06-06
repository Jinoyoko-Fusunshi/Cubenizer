#pragma once

#include "Model.hpp"

class Cube final : public Model  {
public:
    static constexpr uint8_t CubeFaceCount = 6; 
    static constexpr double ModelWidth = 400.0;

    explicit Cube(Vector3D position, Mesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference) : 
        Model(position, geometry_object_reference, shader_reference, texture_reference) {}
    ~Cube() override {}

    void UpdateFaces(const int* face_ids);
    void DrawModel(const Matrix4F &view_matrix_reference, const Matrix4F &projection_matrix_reference) override;
};