#pragma once

#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "TextureTypes.hpp"
#include "RenderingSystem.hpp"

class Model {
protected:
    Vector3F position {};
    Texture texture {};
    Mesh mesh {};
    ShaderProgram shader {};

public:
    explicit Model(Vector3F position, Mesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference) : 
        position(position), mesh(geometry_object_reference), shader(shader_reference), texture(texture_reference) {}
    virtual ~Model() = default;

    virtual void DrawModel(const Matrix4F &view_matrix_reference, const Matrix4F &projection_matrix_reference) {}

    void CreateGraphicalModel(RenderingSystem &renderer_reference);

    Matrix4F GetModelMatrix();
};