#include "Camera.hpp"

void Camera::TranslateCamera(Vector3F translation_vector) {
    position += translation_vector;
}