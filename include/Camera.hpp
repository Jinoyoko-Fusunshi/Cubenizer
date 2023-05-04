#pragma once

#include "Vector.hpp"

class Camera{
private:
    Vector3F position;

public:
    Camera() : position(Vector3F()) {}
    explicit Camera(Vector3F position) : position(position) {}

    void TranslateCamera(Vector3F translation_vector);

    Vector3F &GetPosition() { return position; };
};