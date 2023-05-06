#pragma once

#include "Common.hpp"
#include "Vector2.hpp"

template<typename N>
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

typedef Vector3<float> Vector3F;