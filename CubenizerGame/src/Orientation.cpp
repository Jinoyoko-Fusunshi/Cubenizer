#include "Orientation.hpp"

Matrix4F Orientation::GetTransformation() {
    Matrix4F rotation_matrix = GetRotation();
    return rotation_matrix * position_translation;
}