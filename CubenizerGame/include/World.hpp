#include <vector>
#include "Model.hpp"
#include "Camera.hpp"
#include "Rendering.hpp"

class World {
private:
    uint32_t tiles_width = 0;
    uint32_t tiles_height = 0;
    uint32_t tiles_depth = 0;
    Camera camera = Camera(Vector3F(0.0, 0.0, 2.0));
    std::vector<Model> models {};

    void DrawModels();

public:
    explicit World(uint32_t width, uint32_t depth, uint32_t height);
    ~World() = default;

    void InitModels(RenderingSystem &render_system);
    void DrawWorld();

    Camera& GetCamera() { return camera; }
};