#include "Vector.hpp"

Vector3f AddVector(Vector3f first, Vector3f second) {
    Vector3f sum = {
        .x = first.x + second.x,
        .y = first.y + second.y,
        .z = first.z + second.z
    };

    return sum;
}

Vector3f SubVector(Vector3f first, Vector3f second) {
    Vector3f sum = {
        .x = first.x - second.x,
        .y = first.y - second.y,
        .z = first.z - second.z
    };

    return sum;
}

void AddToVector(Vector3f* target_reference, Vector3f other) {
    target_reference->x += other.x;
    target_reference->y += other.y;
    target_reference->z += other.z;
}

void SubOfVector(Vector3f* target_reference, Vector3f other) {
    target_reference->x -= other.x;
    target_reference->y -= other.y;
    target_reference->z -= other.z;
}