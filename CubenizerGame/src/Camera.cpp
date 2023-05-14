#include "Camera.hpp"

Camera::Camera(Vector3F position, float camera_speed) : position(position), camera_speed(camera_speed) {
    projection = Matrix4F::ProjectionMatrix(1.0, 100.0, 90.0);
}

void Camera::UpdateView() {
    auto inverted_position = position * -1.0;
    orientation.SetYawRotation(FDegree(yaw_angle));
    orientation.SetPitchRotation(FDegree(pitch_angle));
    orientation.SetRollRotation(FDegree(roll_angle));
    orientation.SetTranslation(inverted_position);
    view_matrix = orientation.GetTransformation();
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