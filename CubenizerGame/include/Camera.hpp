#pragma once

#include <Vector3.hpp>
#include <Matrix4.hpp>

class Camera{
private:
    Vector3F position;

    static Matrix4F projection;

public:
    Camera() : position(Vector3F()) {}
    explicit Camera(Vector3F position) : position(position) {}
    ~Camera() = default;

    void TranslateCamera(Vector3F translation_vector);

    Vector3F &GetPosition() { return position; };
    Matrix4F GetViewMatrix();

    static void CreateProjection(float fov, float near_distance, float far_distance);
    static Matrix4F& GetProjection() { return projection; }
};