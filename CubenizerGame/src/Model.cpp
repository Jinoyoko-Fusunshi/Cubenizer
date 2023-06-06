#include <cstdlib>
#include "Model.hpp"
#include "Camera.hpp"

void Model::CreateGraphicalModel(RenderingSystem &renderer_reference) {
    
}

Matrix4F Model::GetModelMatrix() {
    auto screen_space_position = Camera::GetScreenTransformationMatrix() * Vector4D(position, 1.0);

    float elements[MatrixDimension * MatrixDimension] = {
        1.0, 0.0, 0.0, screen_space_position.GetX(),
        0.0, 1.0, 0.0, screen_space_position.GetY(),
        0.0, 0.0, 1.0, screen_space_position.GetZ(),
        0.0, 0.0, 0.0, 1.0,
    };

    return Matrix4F(elements);
}