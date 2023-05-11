#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"
#include "World.hpp"
#include "Rendering.hpp"

using std::vector;

void HandleInput(GLFWwindow* window, World &world_reference);
void DrawScreen(RenderWindow *window_reference, World &world_reference);

int main() {
    RenderWindow window("Test 3D-GL Window", 800, 600);
    RenderingSystem render_system;
    render_system.CreateShaders();

    World world(100, 100, 1);
    world.InitModels(render_system);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window.getHandle())) {
        glfwPollEvents();
        HandleInput(window.getHandle(), world);
        DrawScreen(&window, world);
    }

    glDisable(GL_DEPTH_TEST);

    glfwMakeContextCurrent(nullptr);
    glfwTerminate();
    glfwDestroyWindow(window.getHandle());

    return EXIT_SUCCESS;
}

void HandleInput(GLFWwindow* window, World &world_reference) {
    if (glfwGetKey(window, GLFW_KEY_W))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0, 0.0, -0.1));

    if (glfwGetKey(window,GLFW_KEY_S))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0f, 0.0f, 0.1f));

    if (glfwGetKey(window,GLFW_KEY_A))
        world_reference.GetCamera().TranslateCamera(Vector3F(-0.1f, 0.0f, 0.0f));

    if (glfwGetKey(window,GLFW_KEY_D))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.1f, 0.0f, 0.0f));

    if (glfwGetKey(window,GLFW_KEY_LEFT_CONTROL))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0f, -0.1f, 0.0f));

    if (glfwGetKey(window,GLFW_KEY_SPACE))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0f, 0.1f, 0.0f));
}

void DrawScreen(RenderWindow *window_reference, World &world_reference) {
    glClearColor ( 0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    world_reference.DrawWorld();
    glfwSwapBuffers(window_reference->getHandle());
}