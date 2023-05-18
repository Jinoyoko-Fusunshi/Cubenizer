#pragma once

#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "Orientation.hpp"
#include "Viewport.hpp"

class Camera {
private:
    float camera_speed = 0.2;
    float yaw_angle = 0.0;
    float pitch_angle = 0.0;
    float roll_angle = 0.0;

    Vector3F position {};
    Matrix4F view_matrix = Matrix4F::IdentityMatrix();
    Matrix4F projection_matrix = Matrix4F::IdentityMatrix();
    Matrix4F screen_translation_matrix = Matrix4F::IdentityMatrix();
    Orientation orientation_matrix {};
    Viewport camera_viewport {};

public:
    Camera() = default;
    explicit Camera(Vector3F position, Viewport camera_viewport, float camera_speed);
    ~Camera() = default;

    void UpdateView();
    void TranslateCamera(Vector3F translation);
    void YawBy(float angle_in_degrees);
    void PitchBy(float angle_in_degrees);
    void RollBy(float angle_in_degrees);

    Vector3F& GetPosition() { return position; }
    Matrix4F& GetViewMatrix() { return view_matrix; }
    Matrix4F& GetProjectionMatrix() { return projection_matrix; }
};