#include <cstdio>
#include <vector>
#include <fstream>
#include "Common.hpp"
#include "ShaderUnit.hpp"

using std::vector, std::ifstream, std::ios;

GLuint CreateShaderUnit(const char *shader_path, GLenum shader_type) {
    ifstream file_reader(shader_path, ios::ate | ios::binary);

    if(!file_reader.is_open())
        printf("error!");

    const uint32_t file_size = static_cast<uint32_t>(file_reader.tellg()) + 1;
    vector<char> file_content(file_size);
    file_reader.seekg(0);
    file_reader.read(file_content.data(), file_size);
    file_reader.close();

    const char *shader_source = file_content.data();
    GLuint shader_unit = glCreateShader(shader_type);
    glShaderSource(shader_unit, 1, &shader_source, nullptr);
    glCompileShader(shader_unit);

    GLint shader_status;
    glGetShaderiv(shader_unit, GL_COMPILE_STATUS, &shader_status);

    if (shader_status != GL_TRUE) {
        char error_message[string_buffer_size];
        glGetShaderInfoLog(shader_unit, string_buffer_size, nullptr, error_message);
        printf("Shader compilation error on %s: %s", shader_path, error_message);
        return 0;
    }

    return shader_unit;
}

GLuint CreateShaderProgram(vector<ShaderInformation> &shader_infos_reference) {
    vector<GLuint> shader_units {};
    GLuint program_id = glCreateProgram();

    for (auto information : shader_infos_reference) {
        GLuint shader = CreateShaderUnit(information.source_path, information.shader_type);
        shader_units.emplace_back(shader);
        glAttachShader(program_id, shader);
    }

    GLint program_status;
    glLinkProgram(program_id);
    glGetProgramiv(program_id, GL_LINK_STATUS, &program_status);

    if (program_status != GL_TRUE) {
        char error_message[string_buffer_size];
        glGetProgramInfoLog(program_id, string_buffer_size, nullptr, error_message);

        printf("Shader program linker error: %s", error_message);
    }

    for (unsigned int shader : shader_units)
        glDeleteShader(shader);

    return program_id;
}