#include "World.hpp"
#include "MeshTypes.hpp"

Matrix4F projection;

World::World(uint32_t width, uint32_t depth) {
    tiles_width = width;
    tiles_depth = depth;
    projection = Matrix4F::CreateProjectionMatrix(90.0f, 1.0f, 100.0f);
}

World::~World() = default;

void World::InitModels(RenderingSystem &render_system) {
    ShaderProgram program = render_system.GetShadersReference()[0];
    GeometryMesh object = render_system.GetMeshByType(MeshTypes::Cube);
    Texture texture = render_system.GetTextureByType(TextureTypes::Troll);

    for (uint32_t z = 0; z < tiles_depth; z++) {
        for (uint32_t x = 0; x < tiles_width; x++) {
            auto x_pos = 0.0f + (float)x;
            auto z_pos = 0.0f - (float)z;
            auto y_pos = 0.0f;

            Vector3F position(x_pos, y_pos, z_pos);
            Model model(position, object, program, texture);
            models.emplace_back(model);
        }
    }
}

void World::DrawWorld() {
    DrawModels();
}

void World::DrawModels() {
    auto x_span = 20.0;
    auto y_span = 2.0;
    auto z_span = 20.0;

    auto x_tile_start = (int32_t)((-10.0 + camera.GetPosition().GetX()));
    auto x_tile_end = (int32_t)((camera.GetPosition().GetX() + x_span));
    double y_tile_start = 0.0 - camera.GetPosition().GetY();
    double y_tile_end = 0.0 - camera.GetPosition().GetY() + y_span;
    auto z_tile_start = (int32_t)((0.0 - camera.GetPosition().GetZ()));
    auto z_tile_end = (int32_t)((0.0 - camera.GetPosition().GetZ() + z_span));

    if (x_tile_end > tiles_width)
        x_tile_end = (int32_t)tiles_width;

    if (x_tile_start < 0)
        x_tile_start = 0;

    if (z_tile_end > tiles_depth)
        z_tile_end = (int32_t)tiles_depth;

    if (z_tile_start < 0)
        z_tile_start = 0;

    for (int32_t z = z_tile_start; z < z_tile_end; z++) {
        for (int32_t x = x_tile_start; x < x_tile_end; x++) {
            Model current_model = models[(z * tiles_width) + x];

            int32_t bottom_z = z + 1;
            int32_t top_z = z - 1;
            int32_t left_x = x - 1;
            int32_t right_x = x + 1;
            int32_t top_y = 1;
            int32_t bottom_y = 0;

            int face_ids[6] = {0, 0, 0, 0, 0, 0};

            if (left_x >= 0)
                face_ids[2] = 1;

            if (right_x < tiles_width)
                face_ids[1] = 1;

            if (top_z >= 0)
                face_ids[0] = 1;

            if (bottom_z < tiles_depth)
                face_ids[3] = 1;

            current_model.UpdateProjectionMatrix(projection);
            current_model.UpdateModelPosition();
            current_model.UpdateCameraPosition(camera.GetPosition());
            current_model.UpdateColor(current_model.GetColor());
            current_model.UpdateFaces(face_ids, 6);
            current_model.DrawModel();
        }
    }
}