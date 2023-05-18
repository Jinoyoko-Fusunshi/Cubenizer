#include "World.hpp"
#include "MeshTypes.hpp"

World::World(uint32_t width, uint32_t depth, uint32_t height) {
    tiles_width = width;
    tiles_height = height;
    tiles_depth = depth;
}

void World::CreateCamera(Vector3F position, Viewport camera_viewport, float camera_speed) {
    camera = Camera(position, camera_viewport, camera_speed);
}

void World::InitModels(RenderingSystem &render_system) {
    ShaderProgram program = render_system.GetShadersReference(0);
    GeometryMesh object = render_system.GetMeshByType(MeshTypes::Cube);
    Texture texture = render_system.GetTextureByType(TextureTypes::Troll);

    for (uint32_t y_tile = 0; y_tile < tiles_height; y_tile++) {
        for (uint32_t z_tile = 0; z_tile < tiles_depth; z_tile++) {
            for (uint32_t x_tile = 0; x_tile < tiles_width; x_tile++) {
                auto x_pos = 0.0f + (float)x_tile;
                auto y_pos = 0.0f + (float)y_tile;
                auto z_pos = 0.0f - (float)z_tile;

                Vector3F position(x_pos, y_pos, z_pos);
                Model model(position, object, program, texture);
                models.emplace_back(model);
            }
        }
    }
}

void World::DrawWorld() {
    DrawModels();
}

void World::DrawModels() {
    auto x_tiles_amount = 20.0;
    auto y_tiles_amount = 20.0;
    auto z_tiles_amount = 20.0;

    auto y_tile_start = (int32_t)(-10.0 + camera.GetPosition().GetY());
    auto y_tile_end = (int32_t)(0.0 + camera.GetPosition().GetY() + y_tiles_amount);
    auto x_tile_start = (int32_t)((-10.0 + camera.GetPosition().GetX()));
    auto x_tile_end = (int32_t)((0.0 + camera.GetPosition().GetX() + x_tiles_amount));
    auto z_tile_start = (int32_t)((0.0 - camera.GetPosition().GetZ()));
    auto z_tile_end = (int32_t)((0.0 - camera.GetPosition().GetZ() + z_tiles_amount));

    if (y_tile_end > tiles_height)
        y_tile_end = (int32_t)tiles_height;

    if (y_tile_start < 0)
        y_tile_start = 0;

    if (x_tile_end > tiles_width)
        x_tile_end = (int32_t)tiles_width;

    if (x_tile_start < 0)
        x_tile_start = 0;

    if (z_tile_end > tiles_depth)
        z_tile_end = (int32_t)tiles_depth;

    if (z_tile_start < 0)
        z_tile_start = 0;

    for (int32_t y_tile = 0; y_tile < tiles_height; y_tile++) {
        for (int32_t z_tile = 0; z_tile < tiles_depth; z_tile++) {
            for (int32_t x_tile = 0; x_tile < tiles_width; x_tile++) {
                uint32_t tile_layer = y_tile * (tiles_depth * tiles_width);
                uint32_t tile_position = z_tile * tiles_width + x_tile;
                uint32_t tile_index = tile_layer + tile_position;

                Model current_model = models[tile_index];

                int32_t tile_top_index = y_tile + 1;
                int32_t tile_bottom_index = y_tile - 1;
                int32_t tile_front_index = z_tile + 1;
                int32_t tile_back_index = z_tile - 1;
                int32_t tile_left_index = x_tile - 1;
                int32_t tile_right_index = x_tile + 1;

                int tile_face_ids[6] = {0, 0, 0, 0, 0, 0};

                if (tile_bottom_index >= 0)
                    tile_face_ids[5] = 1;

                if (tile_top_index < tiles_height)
                    tile_face_ids[4] = 1;

                if (tile_left_index >= 0)
                    tile_face_ids[2] = 1;

                if (tile_right_index < tiles_width)
                    tile_face_ids[1] = 1;

                if (tile_back_index >= 0)
                    tile_face_ids[0] = 1;

                if (tile_front_index < tiles_depth)
                    tile_face_ids[3] = 1;

                current_model.UpdateModelMatrix();
                current_model.UpdateViewMatrix(camera.GetViewMatrix());
                current_model.UpdateProjectionMatrix(camera.GetProjectionMatrix());
                current_model.UpdateColor();
                current_model.UpdateFaces(tile_face_ids, 6);
                current_model.DrawModel();
            }
        }
    }
}