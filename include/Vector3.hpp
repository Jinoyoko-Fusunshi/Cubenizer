#pragma once

#include "Common.hpp"
#include "Vector2.hpp"

template<FloatType N>
class Vector3 final : public Vector2<N> {
protected:
    N z = 0.0;

public:
    Vector3() : Vector2<N>(), z(0) {}
    explicit Vector3(N x, N y, N z) : Vector2<N>(x, y), z(z) {}
    ~Vector3() = default;

    N GetZ() { return z; }

    Vector3<N> operator +(Vector3<N> other);
    void operator +=(Vector3<N> other);
    Vector3<N> operator -(Vector3<N> other);
    void operator -=(Vector3<N> other);
};

template<FloatType N> Vector3<N> Vector3<N>::operator-(Vector3<N> other) {
    return Vector3<N>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template<FloatType N> void Vector3<N>::operator-=(Vector3<N> other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
}

template<FloatType N> Vector3<N> Vector3<N>::operator+(Vector3<N> other) {
    return Vector3<N>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<FloatType N> void Vector3<N>::operator+=(Vector3<N> other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}

typedef Vector3<float> Vector3F;