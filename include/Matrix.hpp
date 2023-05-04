#pragma once

#include <stdint-gcc.h>
#include <cmath>
#include "Vector.hpp"

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

    Vector3<N> operator *(Vector3<N> other);
};

template<FloatType N> Matrix4<N>::Matrix4(N *elements) {
    for (uint16_t i = 0u; i < MatrixDimension * MatrixDimension; i++)
        this->elements[i] = elements[i];
}

template<FloatType N> Matrix4<N> Matrix4<N>::CreateIdentityMatrix() {
    Matrix4<N> matrix({
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    });

    return matrix;
}

template<FloatType N> Matrix4<N> Matrix4<N>::CreateProjectionMatrix(N fov, N near_distance, N far_distance) {
    N scale = 1.0 / (tan((fov / 2.0) * ((N)M_PI / 180.0)));

    N elements[MatrixDimension * MatrixDimension] = {
        scale, 0.0, 0.0, 0.0,
        0.0, scale, 0.0, 0.0,
        0.0, 0.0, -(far_distance / (far_distance - near_distance)), -1.0,
        0.0, 0.0, -((far_distance * near_distance) / (far_distance - near_distance)), 0.0,
    };

    return Matrix4<N>(elements);
}

template<FloatType N> Vector3<N> Matrix4<N>::operator*(Vector3<N> other) {
    double vector_data[4] = {other.GetX(), other.GetY(), other.GetZ(), 0.0};
    double vector_result_data[4] = {0.0, 0.0, 0.0, 0.0};

    for (uint16_t i = 0; i < MatrixDimension; i++) {
        for (uint16_t j = 0; j < MatrixDimension; j++) {
            uint16_t vector_index = j;
            uint16_t matrix_index = (i * MatrixDimension) + j;

            vector_result_data[vector_index] += vector_data[j] * elements[matrix_index];
        }
    }

    Vector3<N> vector_result(vector_result_data[0], vector_result_data[1], vector_result_data[2]);
    return vector_result;
}

typedef Matrix4<float> Matrix4F;