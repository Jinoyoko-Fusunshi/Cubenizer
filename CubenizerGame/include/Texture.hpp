#pragma once

#include <GL/glew.h>
#include <string>

class Texture {
private:
    GLuint texture_id = 0;

public:
    Texture() = default;
    explicit Texture(const std::string& texture_file_path);
    ~Texture() = default;

    void Destroy();

    GLuint GetTextureID() { return texture_id; }
};