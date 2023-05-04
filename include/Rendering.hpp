#pragma once

#include <vector>
#include <map>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Geometry.hpp"
#include "ShaderProgram.hpp"
#include "ShaderUnit.hpp"
#include "GeometryObject.hpp"

class RenderingSystem {
private:
    std::vector<ShaderProgram> shaders_programs;
    std::map<uint32_t, GeometryObject> geometry_objects;

public:
    RenderingSystem();
    ~RenderingSystem() = default;
    void CreateShaders();

    std::vector<ShaderProgram>& GetShadersReference() { return shaders_programs; }
    std::map<uint32_t, GeometryObject>& GetGeometryObjectsReference() { return geometry_objects; }
};

GLuint CreateVertexArrayObject();
GLuint CreateVertexBufferObject();

void SetVector3fUniformData(GLuint program_id, const char* uniform_name, Vector3F &data_reference);
void SetMatrix4fUniformData(GLuint program_id, const char* uniform_name, Matrix4F &data_reference);