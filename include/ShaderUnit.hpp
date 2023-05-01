#pragma once

#include <vector>
#include <GL/glew.h>

#include "List.hpp"

typedef struct {
    const char* source_path;
    const GLenum shader_type;
} ShaderInformation;

GLuint CreateShaderUnit(const char *shader_path, GLenum shader_type);
GLuint CreateShaderProgram(std::vector<ShaderInformation> &shader_infos_reference);
