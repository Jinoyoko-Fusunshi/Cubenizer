#pragma once

#include <stdint-gcc.h>
#include "Vector.h"

#define MATRIX_DIMENSION 4

typedef struct {
    float elements[MATRIX_DIMENSION * MATRIX_DIMENSION];
} Matrix4f;

void InitMatrix(Matrix4f *matrix_reference);
void SetMatrixVectorColumn(Matrix4f *matrix_reference, uint16_t column_index, Vector3f vector);
Vector3f MultiplyMatrixVector(Matrix4f matrix, Vector3f vector);
Matrix4f CreateProjectionMatrix(float fov, float near_distance, float far_distance);