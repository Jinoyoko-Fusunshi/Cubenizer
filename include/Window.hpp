#pragma once

#include <GLFW/glfw3.h>
#include "List.hpp"

typedef struct RenderWindow{
    uint32_t width;
    uint32_t height;
    GLFWwindow *handle;
} RenderWindow;

RenderWindow CreateWindow(const char* window_title, uint32_t width, uint32_t height);
void DeleteWindow(RenderWindow *window_reference);