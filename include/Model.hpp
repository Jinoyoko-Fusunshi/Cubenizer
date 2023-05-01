#pragma once

#include "Vector.hpp"
#include "ShaderProgram.hpp"
#include "Matrix.hpp"
#include "GeometryObject.hpp"

typedef struct {
    Vector3f position;
    GeometryObject* geometry;
    ShaderProgram shader;
    Vector3f color;
} Model;

Model* CreateModel(GeometryObject *object_reference_reference, GLuint program_id, Vector3f position);
void UpdateProjectionMatrix(Model* model_reference, Matrix4f* projection_matrix);
void UpdateModelPosition(Model* model_reference);
void UpdateCameraPosition(Model* model_reference, Vector3f cam_position);
void UpdateColor(Model* model_reference, Vector3f color);
void UpdateFaces(Model* model_reference, int* face_ids, int face_length);
void DrawModel(Model *model_reference);