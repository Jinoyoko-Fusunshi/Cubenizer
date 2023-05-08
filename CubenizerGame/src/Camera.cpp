#include "Camera.hpp"

Matrix4<float> Camera::projection;

void Camera::TranslateCamera(Vector3F translation_vector) {
    position += translation_vector;
}

Matrix4F Camera::GetViewMatrix() {
    Matrix4F view_matrix = Matrix4F(
        Vector3F(1.0, 0.0, 0.0), Vector3F(0.0, 1.0, 0.0),
        Vector3F(0.0, 0.0, -1.0), position
    );

    return view_matrix;
}

void Camera::CreateProjection(float fov, float near_distance, float far_distance) {
    projection = Matrix4F::CreateProjectionMatrix(fov, near_distance, far_distance);
}