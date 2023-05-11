#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "STBImage.h"

Texture::Texture(const std::string& texture_file_path) {
    int width = 0, height = 0, channels = 0;
    unsigned char *image_data = stbi_load(texture_file_path.c_str(), &width, &height, &channels, 0);

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

    stbi_image_free(image_data);
}

void Texture::Destroy() {
    glDeleteTextures(1, &texture_id);
}
