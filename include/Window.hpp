#pragma once

#include <string>
#include <GLFW/glfw3.h>

class RenderWindow {
private:
    uint32_t width;
    uint32_t height;
    GLFWwindow *handle = nullptr;

public:
    explicit RenderWindow(const std::string& window_title, uint32_t width, uint32_t height);
    ~RenderWindow() = default;

    GLFWwindow* getHandle() { return handle; }
};