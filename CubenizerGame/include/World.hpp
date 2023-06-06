#include <vector>
#include "Model.hpp"
#include "Camera.hpp"
#include "RenderingSystem.hpp"

class World {
private:
    uint32_t tiles_width = 0;
    uint32_t tiles_height = 0;
    uint32_t tiles_depth = 0;
    Camera camera {};
    std::vector<Model> models {};

    void DrawModels();

public:
    explicit World(uint32_t width, uint32_t depth, uint32_t height);
    ~World() = default;

    void CreateCamera(Vector3F position, Viewport camera_viewport, float camera_speed = 0.2);
    void InitModels(RenderingSystem &render_system);
    void DrawWorld();

    Camera& GetCamera() { return camera; }
};