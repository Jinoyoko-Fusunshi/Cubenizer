#pragma once

#include "Common.hpp"

template<FloatType N>
class Vector2 {
protected:
    N x = 0.0;
    N y = 0.0;

public:
    Vector2() : x(0), y(0) {}
    explicit Vector2(N x, N y) : x(x), y(y) {}
    ~Vector2() = default;

    N GetX() { return x; }
    N GetY() { return y; }

    Vector2<N> operator +(Vector2<N> other);
    void operator +=(Vector2<N> other);
    Vector2<N> operator -(Vector2<N> other);
    void operator -=(Vector2<N> other);
};

typedef Vector2<float> Vector2F;