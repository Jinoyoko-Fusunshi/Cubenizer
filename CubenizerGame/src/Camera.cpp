#include "Camera.hpp"

Matrix4<float> Camera::projection;

void Camera::TranslateCamera(Vector3F translation_vector) {
    position += translation_vector;
}

Matrix4F Camera::GetViewMatrix() {
    auto inverted_vector = position * -1.0;
    return Matrix4F::CreateTranslationMatrix(inverted_vector);
}

void Camera::CreateProjection(float near_distance, float far_distance, float fov) {
    auto scale = 1.0f / (tanf((fov / 2.0f) * ((float)M_PI / 180.0f)));
    float elements[MatrixDimension * MatrixDimension] = {
        scale, 0.0, 0.0, 0.0,
        0.0, scale, 0.0, 0.0,
        0.0, 0.0, -(far_distance / (far_distance - near_distance)), -1.0,
        0.0, 0.0, -((far_distance * near_distance) / (far_distance - near_distance)), 1.0,
    };

    projection = Matrix4F(elements);
}