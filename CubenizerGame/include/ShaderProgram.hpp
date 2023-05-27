#pragma once

#include <string>
#include <GL/glew.h>
#include <Vector3.hpp>
#include <Matrix4.hpp>
#include "MeshData.hpp"

class ShaderProgram {
private:
    GLuint program_id = 0;

public:
    ShaderProgram() = default;
    explicit ShaderProgram(GLuint program_id) : program_id(program_id) {}
    ~ShaderProgram() = default;

    void Destroy() const;

    void SetVector3fUniformData(const std::string& uniform_name, const Vector3F &data_reference) const;
    void SetMatrix4fUniformData(const std::string& uniform_name, const Matrix4F &data_reference) const;

    [[nodiscard]] GLuint GetProgramID() const { return program_id; }
};