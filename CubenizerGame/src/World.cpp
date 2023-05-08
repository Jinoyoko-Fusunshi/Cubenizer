#include "World.hpp"
#include "MeshTypes.hpp"

World::World(uint32_t width, uint32_t depth, uint32_t height) {
    tiles_width = width;
    tiles_height = height;
    tiles_depth = depth;

    Camera::CreateProjection(90.0f, 1.0f, 100.0f);
}

void World::InitModels(RenderingSystem &render_system) {
    ShaderProgram program = render_system.GetShadersReference()[0];
    GeometryMesh object = render_system.GetMeshByType(MeshTypes::Cube);
    Texture texture = render_system.GetTextureByType(TextureTypes::Troll);

    for (uint32_t y = 0; y < tiles_height; y++) {
        for (uint32_t z = 0; z < tiles_depth; z++) {
            for (uint32_t x = 0; x < tiles_width; x++) {
                auto x_pos = 0.0f + (float)x;
                auto y_pos = 0.0f + (float)y;
                auto z_pos = 0.0f - (float)z;

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
    auto x_span = 20.0;
    auto y_span = 20.0;
    auto z_span = 20.0;

    auto y_tile_start = (int32_t)(-10.0 + camera.GetPosition().GetY());
    auto y_tile_end = (int32_t)(0.0 + camera.GetPosition().GetY() + y_span);
    auto x_tile_start = (int32_t)((-10.0 + camera.GetPosition().GetX()));
    auto x_tile_end = (int32_t)((0.0 + camera.GetPosition().GetX() + x_span));
    auto z_tile_start = (int32_t)((0.0 - camera.GetPosition().GetZ()));
    auto z_tile_end = (int32_t)((0.0 - camera.GetPosition().GetZ() + z_span));

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

    auto view_matrix = Matrix4F::CreateIdentityMatrix();

    for (int32_t y = y_tile_start; y < y_tile_end; y++) {
        for (int32_t z = z_tile_start; z < z_tile_end; z++) {
            for (int32_t x = x_tile_start; x < x_tile_end; x++) {
                uint32_t layer = y * (tiles_depth * tiles_width);
                uint32_t position = z * tiles_width + x;
                uint32_t index = layer + position;

                Model current_model = models[index];

                int32_t top_y = y + 1;
                int32_t bottom_y = y - 1;
                int32_t front_z = z + 1;
                int32_t back_z = z - 1;
                int32_t left_x = x - 1;
                int32_t right_x = x + 1;

                int face_ids[6] = {0, 0, 0, 0, 0, 0};

                if (bottom_y >= 0)
                    face_ids[5] = 1;

                if (top_y < tiles_height)
                    face_ids[4] = 1;

                if (left_x >= 0)
                    face_ids[2] = 1;

                if (right_x < tiles_width)
                    face_ids[1] = 1;

                if (back_z >= 0)
                    face_ids[0] = 1;

                if (front_z < tiles_depth)
                    face_ids[3] = 1;

                auto a = Camera::GetProjection();
                auto b = view_matrix;
                auto c = current_model.GetModelMatrix();

                auto sum = a * b * c;

                current_model.UpdateProjectionMatrix(Camera::GetProjection());
                current_model.UpdateModelPosition();
                current_model.UpdateCameraPosition(view_matrix);
                current_model.UpdateColor(current_model.GetColor());
                current_model.UpdateFaces(face_ids, 6);
                current_model.DrawModel();
            }
        }
    }
}