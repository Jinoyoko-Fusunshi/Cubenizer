#include <cstdio>
#include <GL/glew.h>
#include "Window.hpp"

using std::string;

void PrintGLFWError();

RenderWindow::RenderWindow(const string& window_title, uint32_t width, uint32_t height) {
    if (!glfwInit())
        PrintGLFWError();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    handle = glfwCreateWindow((int)width, (int)height, window_title.c_str(), nullptr, nullptr);

    if(!handle)
        PrintGLFWError();

    glfwMakeContextCurrent(handle);
    GLenum status = glewInit();

    if (status != GLEW_OK) {
        const char *error_message = (char*)glewGetErrorString(status);
        printf("GL Error: %s", error_message);
    }
}

void PrintGLFWError() {
    const char *error_message;
    glfwGetError(&error_message);
    printf("GLFW Error: %s", error_message);
}