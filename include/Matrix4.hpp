#pragma once

#include <stdint-gcc.h>
#include <cmath>
#include "Vector3.hpp"

constexpr uint8_t MatrixDimension = 4;

template<FloatType N> class Matrix4 {
private:
    N elements[MatrixDimension * MatrixDimension] = {0};

public:
    Matrix4() = default;
    explicit Matrix4(N *elements);
    ~Matrix4() = default;

    static Matrix4<N> CreateIdentityMatrix();
    static Matrix4<N> CreateProjectionMatrix(N fov, N near_distance, N far_distance);

    N* GetElements() { return elements; }
};

typedef Matrix4<float> Matrix4F;