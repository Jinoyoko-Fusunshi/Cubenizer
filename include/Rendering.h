#pragma once

#include "Vector.h"
#include "Matrix.h"
#include "Geometry.h"
#include "ShaderProgram.h"
#include "ShaderUnit.h"
#include "Set.h"

typedef struct RenderingSystem {
    List shaders;
    Set geometry_objects;
} RenderingSystem;

RenderingSystem CreateRenderingSystem();
Vector3f* AllocateVectors(Vector3f *vectors_reference, uint32_t vectors_length);
GLuint CreateVertexArrayObject();
GLuint CreateVertexBufferObject();

void SetVector3fUniformData(GLuint program_id, const char* uniform_name, Vector3f *data_reference);
void SetMatrix4fUniformData(GLuint program_id, const char* uniform_name, Matrix4f *data_reference);