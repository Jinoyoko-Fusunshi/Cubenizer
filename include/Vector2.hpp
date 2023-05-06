#pragma once

#include "Common.hpp"

template<FloatType N>
class Vector2 {
private:
    N x;
    N y;

public:
    Vector2() : x(0), y(0) {}
    Vector2(N x, N y) : x(x), y(y) {}
    ~Vector2() = default;

    N GetX() { return x; }
    N GetY() { return y; }

    Vector2<N> operator +(Vector2<N> other);
    void operator +=(Vector2<N> other);
    Vector2<N> operator -(Vector2<N> other);
    void operator -=(Vector2<N> other);
};

template<FloatType N> Vector2<N> Vector2<N>::operator-(Vector2<N> other) {
    return Vector2<N>(this->x - other.x, this->y - other.y);
}

template<FloatType N> void Vector2<N>::operator-=(Vector2<N> other) {
    this->x -= other.x;
    this->y -= other.y;
}

template<FloatType N> Vector2<N> Vector2<N>::operator+(Vector2<N> other) {
    return Vector2<N>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<FloatType N> void Vector2<N>::operator+=(Vector2<N> other) {
    this->x += other.x;
    this->y += other.y;
}

typedef Vector2<float> Vector2F;