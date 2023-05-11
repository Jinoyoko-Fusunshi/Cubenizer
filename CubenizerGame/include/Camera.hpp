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

    static void CreateProjection(float near_distance, float far_distance, float fov);
    static Matrix4F& GetProjectionMatrix() { return projection; }
};