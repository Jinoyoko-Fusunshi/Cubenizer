#include "Camera.hpp"

Matrix4F Camera::screen_transformation_matrix = Matrix4F::IdentityMatrix();

Camera::Camera(Vector3F position, Viewport camera_viewport, float camera_speed)
    : position(position), camera_viewport(camera_viewport), camera_speed(camera_speed) {
    projection_matrix = Matrix4F::ProjectionMatrix(camera_viewport.near_distance, camera_viewport.far_distance, camera_viewport.fov);

    uint16_t half_width = camera_viewport.screen_width / 2;
    uint16_t half_height = camera_viewport.screen_height / 2;
    uint16_t half_depth = half_width;

    float elements[MatrixDimension * MatrixDimension] = {
        1.0f / (float)half_width, 0.0, 0.0, -1.0,
        0.0, 1.0f / (float)half_height, 0.0, -1.0,
        0.0, 0.0, 1.0f / (float)half_depth, 1.0,
        0.0, 0.0, 0.0, 1.0
    };

    screen_transformation_matrix = Matrix4F(elements);
}

void Camera::UpdateView() {
    auto inverted_position = position * -1.0;
    orientation_matrix.SetYawRotation(FDegree(yaw_angle));
    orientation_matrix.SetPitchRotation(FDegree(pitch_angle));
    orientation_matrix.SetRollRotation(FDegree(roll_angle));
    orientation_matrix.SetTranslation(inverted_position);
    view_matrix = orientation_matrix.GetTransformation();
}

void Camera::TranslateCamera(Vector3F translation) {
    auto rotation_matrix = Matrix4F::YRotationMatrix(FDegree(-yaw_angle));
    auto view_direction_translation = rotation_matrix * translation;
    position += view_direction_translation * camera_speed;
}

void Camera::YawBy(float angle_in_degrees) {
    yaw_angle += angle_in_degrees;

    if (yaw_angle >= 360.0)
        yaw_angle -= 360.0;

    if (yaw_angle < 0.0)
        yaw_angle += 360.0;
}

void Camera::PitchBy(float angle_in_degrees) {
    pitch_angle += angle_in_degrees;

    if (pitch_angle > 90.0)
        pitch_angle = 90.0;

    if (pitch_angle < -90.0)
        pitch_angle = -90.0;
}

void Camera::RollBy(float angle_in_degrees) {
    roll_angle += angle_in_degrees;

    if (roll_angle >= 360.0)
        roll_angle -= 360.0;

    if (roll_angle < 0.0)
        roll_angle += 360.0;
}