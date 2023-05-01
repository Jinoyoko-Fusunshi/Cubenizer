#include <stdio.h>
#include <string.h>
#include <vector>

#include "Common.hpp"
#include "ShaderUnit.hpp"

using std::vector;

GLuint CreateShaderUnit(const char *shader_path, GLenum shader_type) {
    FILE *shader_file = fopen(shader_path, "rb");

    if(!shader_file) {
        printf("error!");
    }

    fseek(shader_file, 0L, SEEK_END);
    uint32_t file_size = ftell(shader_file) + 1;
    fseek(shader_file, 0L, SEEK_SET);

    char file_content[file_size];
    memset(file_content, '\0', file_size);
    fread(file_content, sizeof(char), file_size - 1, shader_file);
    fclose(shader_file);

    const char *shader_source = file_content;
    GLuint shader_unit = glCreateShader(shader_type);
    glShaderSource(shader_unit, 1, &shader_source, 0);
    glCompileShader(shader_unit);

    GLint shader_status;
    glGetShaderiv(shader_unit, GL_COMPILE_STATUS, &shader_status);

    if (shader_status != GL_TRUE) {
        char error_message[string_buffer_size];
        glGetShaderInfoLog(shader_unit, string_buffer_size, 0, error_message);
        printf("Shader compilation error on %s: %s", shader_path, error_message);
        return 0;
    }

    return shader_unit;
}

GLuint CreateShaderProgram(vector<ShaderInformation> &shader_infos_reference) {
    vector<GLuint> shader_units {};
    GLuint program_id = glCreateProgram();

    for (uint32_t i = 0; i < shader_infos_reference.size(); i++) {
        ShaderInformation information = shader_infos_reference[i];
        GLuint shader = CreateShaderUnit(information.source_path, information.shader_type);
        shader_units.emplace_back(shader);
        glAttachShader(program_id, shader);
    }

    glLinkProgram(program_id);

    GLint program_status;
    glGetProgramiv(program_id, GL_LINK_STATUS, &program_status);

    if (program_status != GL_TRUE) {
        char error_message[string_buffer_size];
        glGetProgramInfoLog(program_id, string_buffer_size, 0, error_message);

        printf("Shader program linker error: %s", error_message);
    }

    for (uint32_t i = 0; i < shader_units.size(); i++) {
        GLuint shader = shader_units[i];
        glDeleteShader(shader);
    }

    return program_id;
}