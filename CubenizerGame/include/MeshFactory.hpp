#pragma once

#include "Mesh.hpp"

class MeshFactory {
public:
    static Mesh CreateCubeMesh(double width, double height, double depth);
};