#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include "Vector2.hpp"

class RenderWindow {
private:
    Vector2F window_size;
    GLFWwindow *handle = nullptr;

public:
    explicit RenderWindow(const std::string& window_title, Vector2F size);
    ~RenderWindow() = default;

    Vector2F GetSize() { return window_size; }
    GLFWwindow* getHandle() { return handle; }
};