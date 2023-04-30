#include <stdio.h>
#include <GL/glew.h>
#include "Window.h"

void PrintGLFWError();

RenderWindow CreateWindow(const char *window_title, uint32_t width, uint32_t height) {
    RenderWindow window;

    if (!glfwInit())
        PrintGLFWError();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *handle = glfwCreateWindow((int)width, (int)height, window_title, 0, 0);

    if(!handle)
        PrintGLFWError();

    glfwMakeContextCurrent(handle);
    GLenum status = glewInit();

    if (status != GLEW_OK) {
        const char *error_message = (char*)glewGetErrorString(status);
        printf("GL Error: %s", error_message);
    }

    window.width = width;
    window.height = height;
    window.handle = handle;

    return window;
}

void PrintGLFWError() {
    const char *error_message;
    glfwGetError(&error_message);
    printf("GLFW Error: %s", error_message);
}

void DeleteWindow(RenderWindow *window_reference) {
    glfwDestroyWindow(window_reference->handle);
    glfwTerminate();
}