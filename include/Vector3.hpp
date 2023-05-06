#pragma once

#include "Common.hpp"

template<FloatType N>
class Vector3 {
private:
    N x;
    N y;
    N z;

public:
    Vector3() : x(0), y(0), z(0) {}
    Vector3(N x, N y, N z) : x(x), y(y), z(z) {}
    ~Vector3() = default;

    N GetX() { return x; }
    N GetY() { return y; }
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