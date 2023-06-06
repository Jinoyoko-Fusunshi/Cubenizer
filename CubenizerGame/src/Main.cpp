#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"
#include "World.hpp"
#include "RenderingSystem.hpp"

using std::vector;

const double MouseSensitivity = 0.5;
const Vector3F BackgroundColor(0.2, 0.2, 0.2);

double mouse_pos_x = 0.0, mouse_pos_y = 0.0;

void HandleInput(GLFWwindow* window, World &world_reference);
void HandleMouseInput(GLFWwindow* window, World &world_reference);
void HandleKeyboardInput(GLFWwindow* window, World &world_reference);
void DrawScreen(RenderWindow *window_reference, World &world_reference);

int main() {
    RenderWindow window("Test 3D-GL Window", Vector2F(800.0, 600.0));
    glfwGetCursorPos(window.getHandle(), &mouse_pos_x, &mouse_pos_y);

    RenderingSystem render_system;
    render_system.CreateShaders();
    render_system.CreateTextures();

    Viewport viewport = {
        .fov = 90.0,
        .near_distance = 1.0,
        .far_distance = 100.0,
        .screen_width = (uint16_t)window.GetSize().GetX(),
        .screen_height = (uint16_t)window.GetSize().GetY()
    };

    World world(100, 100, 1);
    world.CreateCamera(Vector3F(0.0, 0.0, 2.0), viewport);
    render_system.CreateGeometries();
    world.InitModels(render_system);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

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
    HandleKeyboardInput(window, world_reference);
    HandleMouseInput(window, world_reference);

    world_reference.GetCamera().UpdateView();
}

void HandleKeyboardInput(GLFWwindow* window, World &world_reference) {
    if (glfwGetKey(window, GLFW_KEY_W))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0, 0.0, -1.0));

    if (glfwGetKey(window,GLFW_KEY_S))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0, 0.0, 1.0));

    if (glfwGetKey(window,GLFW_KEY_A))
        world_reference.GetCamera().TranslateCamera(Vector3F(-1.0, 0.0, 0.0));

    if (glfwGetKey(window,GLFW_KEY_D))
        world_reference.GetCamera().TranslateCamera(Vector3F(1.0, 0.0, 0.0));

    if (glfwGetKey(window,GLFW_KEY_LEFT_CONTROL))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0, -1.0, 0.0));

    if (glfwGetKey(window,GLFW_KEY_SPACE))
        world_reference.GetCamera().TranslateCamera(Vector3F(0.0, 1.0, 0.0));
}

void HandleMouseInput(GLFWwindow* window, World &world_reference) {
    double current_mouse_pos_x = 0.0, current_mouse_pos_y = 0.0;
    glfwGetCursorPos(window, &current_mouse_pos_x, &current_mouse_pos_y);

    double delta_x = current_mouse_pos_x - mouse_pos_x;
    double delta_y = current_mouse_pos_y - mouse_pos_y;

    double move_angle_x = delta_x * MouseSensitivity;
    double move_angle_y = delta_y * MouseSensitivity;

    if (delta_x != 0.0)
        world_reference.GetCamera().YawBy((float)move_angle_x);

    if (delta_y != 0.0) {}
        world_reference.GetCamera().PitchBy((float)move_angle_y);

    mouse_pos_x = current_mouse_pos_x;
    mouse_pos_y = current_mouse_pos_y;
}

void DrawScreen(RenderWindow *window_reference, World &world_reference) {
    glClearColor (BackgroundColor.GetX(), BackgroundColor.GetY(), BackgroundColor.GetZ() , 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    world_reference.DrawWorld();
    glfwSwapBuffers(window_reference->getHandle());
}