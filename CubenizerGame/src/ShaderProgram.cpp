#include "ShaderProgram.hpp"

using std::string;

void ShaderProgram::Destroy() const {
    glDeleteProgram(program_id);
}

void ShaderProgram::SetVector3fUniformData(const string &uniform_name, const Vector3F &data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name.c_str());
    glUseProgram(program_id);
    glUniform3f(id, data_reference.GetX(), data_reference.GetY(), data_reference.GetZ());
    glUseProgram(0);
}

void ShaderProgram::SetMatrix4fUniformData(const string &uniform_name, const Matrix4F &data_reference) {
    GLint id = glGetUniformLocation(program_id, uniform_name.c_str());
    glUseProgram(program_id);
    glUniformMatrix4fv(id, 1, 0, data_reference.GetElements());
    glUseProgram(0);
}

void ShaderProgram::SetIntegerArray(const string &uniform_name, const int *data, uint32_t data_length) {
    GLint id = glGetUniformLocation(program_id, uniform_name.c_str());
    glUseProgram(program_id);
    glUniform1iv(id, data_length, data);
    glUseProgram(0);
}
