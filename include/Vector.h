#pragma once

typedef struct {
    float x;
    float y;
    float z;
} Vector3f;

typedef struct {
    Vector3f vertex;
    Vector3f normal;
} VertexData;

Vector3f AddVector(Vector3f first, Vector3f second);
Vector3f SubVector(Vector3f first, Vector3f second);

void AddToVector(Vector3f* target_reference, Vector3f other);
void SubOfVector(Vector3f* target_reference, Vector3f other);