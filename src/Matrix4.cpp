#include "Matrix4.hpp"

template<FloatType N> Matrix4<N>::Matrix4(N *elements) {
    for (uint16_t i = 0u; i < MatrixDimension * MatrixDimension; i++)
        this->elements[i] = elements[i];
}

template<FloatType N> Matrix4<N> Matrix4<N>::CreateIdentityMatrix() {
    N elements[16] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return  Matrix4<N>(elements);
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

template class Matrix4<float>;