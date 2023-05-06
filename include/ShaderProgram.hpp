#pragma once

#include <GL/glew.h>
#include "Geometry.hpp"

class ShaderProgram {
private:
    GLuint program_id = 0;

public:
    ShaderProgram() = default;
    explicit ShaderProgram(GLuint program_id) : program_id(program_id) {}
    ~ShaderProgram() = default;

    void Destroy();

    GLuint GetProgramID() { return program_id; }
};