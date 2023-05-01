#pragma once

#include <vector>

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Geometry.hpp"
#include "ShaderProgram.hpp"
#include "ShaderUnit.hpp"
#include "Set.hpp"

typedef struct RenderingSystem {
    std::vector<GLuint> shaders;
    Set geometry_objects;
} RenderingSystem;

RenderingSystem CreateRenderingSystem();
Vector3f* AllocateVectors(Vector3f *vectors_reference, uint32_t vectors_length);
GLuint CreateVertexArrayObject();
GLuint CreateVertexBufferObject();

void SetVector3fUniformData(GLuint program_id, const char* uniform_name, Vector3f *data_reference);
void SetMatrix4fUniformData(GLuint program_id, const char* uniform_name, Matrix4f *data_reference);