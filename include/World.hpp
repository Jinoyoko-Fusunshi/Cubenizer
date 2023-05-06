#include <vector>
#include "Model.hpp"
#include "Camera.hpp"
#include "Rendering.hpp"

class World {
private:
    uint32_t tiles_width = 0;
    uint32_t tiles_depth = 0;
    std::vector<Model> models {};
    Camera camera {};

    void DrawModels();
public:
    explicit World(uint32_t width, uint32_t depth);
    ~World();

    void InitModels(RenderingSystem &render_system);
    void DrawWorld();

    Camera& GetCamera() { return camera; }
};