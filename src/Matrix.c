#include <math.h>
#include "Matrix.h"

void InitMatrix(Matrix4f *matrix_reference) {
    matrix_reference->elements[0] = 1.0f;
    matrix_reference->elements[1] = 0.0f;
    matrix_reference->elements[2] = 0.0f;
    matrix_reference->elements[3] = 0.0f;
    matrix_reference->elements[4] = 0.0f;
    matrix_reference->elements[5] = 1.0f;
    matrix_reference->elements[6] = 0.0f;
    matrix_reference->elements[7] = 0.0f;
    matrix_reference->elements[8] = 0.0f;
    matrix_reference->elements[9] = 0.0f;
    matrix_reference->elements[10] = 1.0f;
    matrix_reference->elements[11] = 0.0f;
    matrix_reference->elements[12] = 0.0f;
    matrix_reference->elements[13] = 0.0f;
    matrix_reference->elements[14] = 0.0f;
    matrix_reference->elements[15] = 1.0f;
}

void SetMatrixVectorColumn(Matrix4f *matrix_reference, uint16_t column_index, Vector3f vector) {
    float vector_data[4] = {vector.x, vector.y, vector.z, 1.0f};

    if (column_index >= MATRIX_DIMENSION || column_index < 0)
        return;

    for (uint16_t i = 0; i < MATRIX_DIMENSION; i++) {
        uint16_t index = i * MATRIX_DIMENSION + column_index;
        matrix_reference->elements[index] = vector_data[i];
    }
}

Vector3f MultiplyMatrixVector(Matrix4f matrix, Vector3f vector) {
    float vector_data[4] = {vector.x, vector.y, vector.z, 0.0f};
    float vector_result_data[4] = {0.0f, 0.0f, 0.0f, 0.0f};

    for (uint16_t i = 0; i < MATRIX_DIMENSION; i++) {
        for (uint16_t j = 0; j < MATRIX_DIMENSION; j++) {
            uint16_t vector_index = j;
            uint16_t matrix_index = (i * MATRIX_DIMENSION) + j;

            vector_result_data[vector_index] += vector_data[j] * matrix.elements[matrix_index];
        }
    }

    Vector3f vector_result = {vector_result_data[0], vector_result_data[1], vector_result_data[2]};
    return vector_result;
}

Matrix4f CreateProjectionMatrix(float fov, float near_distance, float far_distance) {
    float scale = 1.0f / ((float)tan((fov / 2.0) * (M_PI / 180.0f)));

    Matrix4f projection_matrix = {
        .elements = {
            scale, 0.0f, 0.0f, 0.0f,
            0.0f, scale, 0.0f, 0.0f,
            0.0f, 0.0f, -(far_distance / (far_distance - near_distance)), -1.0f,
            0.0f, 0.0f, -((far_distance * near_distance) / (far_distance - near_distance)), 0.0f,
        }
    };

    return projection_matrix;
}