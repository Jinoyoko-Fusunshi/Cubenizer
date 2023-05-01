#include <vector>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GLFW/glfw3.h>

#include "List.hpp"
#include "Model.hpp"
#include "ShaderUnit.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "World.hpp"
#include "Rendering.hpp"

using std::vector;

void PrintGLFWError();
void InitRenderingSystem();
void CreateShaders();
void InitModels();
void HandleInput(RenderWindow *window_reference);
void DrawScreen(RenderWindow *window_reference);
void DestroyRenderSystem();

RenderingSystem render_system = {};
World world = {};

int main() {
    RenderWindow window = CreateWindow("Test 3D-GL Window", 800, 600);

    world = CreateWorld(20, 20);

    InitRenderingSystem();
    InitModels();

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window.handle)) {
        HandleInput(&window);
        DrawScreen(&window);
    }

    DeleteWorld(&world);
    DestroyRenderSystem();
    DeleteWindow(&window);

    return EXIT_SUCCESS;
}

void InitRenderingSystem() {
    render_system = CreateRenderingSystem();
    CreateShaders();
}

void CreateShaders() {
    vector<ShaderInformation> shader_infos {
        {"vertex.glsl", GL_VERTEX_SHADER},
        {"fragment.glsl", GL_FRAGMENT_SHADER}
    };

    GLuint program_id = CreateShaderProgram(shader_infos);
    render_system.shaders.emplace_back(program_id);
}

void InitModels() {
    GLuint program = render_system.shaders[0];
    Pair *found_pair = GetPairById(&render_system.geometry_objects, Cube);
    GeometryObject *object = (GeometryObject*)found_pair->data;

    for (uint32_t z = 0; z < world.tiles_depth; z++) {
        for (uint32_t x = 0; x < world.tiles_width; x++) {
            float x_pos = 0.0f + (float)x;
            float z_pos = 0.0f - (float)z;
            float y_pos = 0.0f;

            Vector3f position = {x_pos, y_pos, z_pos};
            AddWorldTile(&world, CreateModel(object, program, position));
        }
    }
}

void HandleInput(RenderWindow *window_reference) {
    glfwPollEvents();

    if (glfwGetKey(window_reference->handle, GLFW_KEY_W)){
        Vector3f translation = {0.0f, 0.0f, -0.1f};
        TranslateCamera(&world.camera, translation);
    }

    if (glfwGetKey(window_reference->handle, GLFW_KEY_S)){
        Vector3f translation = {0.0f, 0.0f, 0.1f};
        TranslateCamera(&world.camera, translation);
    }

    if (glfwGetKey(window_reference->handle, GLFW_KEY_A)){
        Vector3f translation = {-0.1f, 0.0f, 0.0f};
        TranslateCamera(&world.camera, translation);
    }

    if (glfwGetKey(window_reference->handle, GLFW_KEY_D)){
        Vector3f translation = {0.1f, 0.0f, 0.0f};
        TranslateCamera(&world.camera, translation);
    }

    if (glfwGetKey(window_reference->handle, GLFW_KEY_LEFT_CONTROL)){
        Vector3f translation = {0.0f, -0.1f, 0.0f};
        TranslateCamera(&world.camera, translation);
    }

    if (glfwGetKey(window_reference->handle, GLFW_KEY_SPACE)){
        Vector3f translation = {0.0f, 0.1f, 0.0f};
        TranslateCamera(&world.camera, translation);
    }
}

void DrawScreen(RenderWindow *window_reference) {
    glClearColor ( 0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DrawWorld(&world);
    glfwSwapBuffers(window_reference->handle);
}

void DestroyRenderSystem() {

}