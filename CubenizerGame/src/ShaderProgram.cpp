#include "ShaderProgram.hpp"

void ShaderProgram::Destroy() {
    glDeleteProgram(program_id);
}