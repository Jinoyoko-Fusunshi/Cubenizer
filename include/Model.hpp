#pragma once

#include "Vector3.hpp"
#include "ShaderProgram.hpp"
#include "Matrix.hpp"
#include "GeometryMesh.hpp"
#include "Texture.hpp"
#include "TextureTypes.hpp"

class Model {
private:
    Vector3F position {};
    Texture texture {};
    GeometryMesh geometry {};
    ShaderProgram shader {};
    Vector3F color {};

public:
    explicit Model(Vector3F position, GeometryMesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference);
    ~Model() = default;
    explicit Model(GeometryObject &geometry_object_reference, ShaderProgram shader_program, Vector3F position);

    void UpdateProjectionMatrix(Matrix4F &projection_matrix);
    void UpdateModelPosition();
    void UpdateCameraPosition(Vector3F &cam_position);
    void UpdateColor(Vector3F &color);
    void UpdateFaces(int* face_ids, int face_length);
    void DrawModel();

    Vector3F& GetColor() { return color; }
};