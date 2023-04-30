#pragma once

#include <GL/glew.h>
#include "List.h"

typedef struct {
    const char* source_path;
    const GLenum shader_type;
} ShaderInformation;

GLuint CreateShaderUnit(const char *shader_path, GLenum shader_type);
GLuint CreateShaderProgram(List *shader_infos_reference);
