#pragma once

#include <vector>
#include <GL/glew.h>
#include <Vector3.hpp>
#include <Vector2.hpp>

struct MeshData {
    std::vector<Vector3D> vertices;
    std::vector<Vector3D> normals;
    std::vector<Vector2D> textures;
    std::vector<GLuint> indices;
};
