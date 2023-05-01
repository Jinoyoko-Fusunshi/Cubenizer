#include "World.hpp"
#include "Camera.hpp"

Matrix4f projection;

void DrawModels(World *world_reference);

World CreateWorld(uint32_t width, uint32_t height) {
    World world = {width, height};
    InitList(&world.models);

    Camera camera = {{0.0f, 0.0f, 0.0f}};
    world.camera = camera;

    projection = CreateProjectionMatrix(90.0f, 1.0f, 100.0f);

    return world;
}

void AddWorldTile(World *world_reference, Model *model_reference) {
    AddListEntry(&world_reference->models, (void*)model_reference);
}

void UpdateWorld(World *world_reference) {

}

void DrawWorld(World *world_reference) {
    DrawModels(world_reference);
}

void DrawModels(World *world_reference) {
    float x_span = 20.0f;
    float y_span = 2.0f;
    float z_span = 20.0f;

    int32_t x_tile_start = (int32_t)((-10.0f + world_reference->camera.position.x));
    int32_t x_tile_end = (int32_t)((world_reference->camera.position.x + x_span));
    float y_tile_start = 0.0f - world_reference->camera.position.y;
    float y_tile_end = 0.0f - world_reference->camera.position.y + y_span;
    int32_t z_tile_start = (int32_t)((0.0f - world_reference->camera.position.z));
    int32_t z_tile_end = (int32_t)((0.0f - world_reference->camera.position.z + z_span));

    if (x_tile_end > world_reference->tiles_width)
        x_tile_end = (int32_t)world_reference->tiles_width;

    if (x_tile_start < 0)
        x_tile_start = 0;

    if (z_tile_end > world_reference->tiles_depth)
        z_tile_end = (int32_t)world_reference->tiles_depth;

    if (z_tile_start < 0)
        z_tile_start = 0;

    for (int32_t z = z_tile_start; z < z_tile_end; z++) {
        for (int32_t x = x_tile_start; x < x_tile_end; x++) {
            Model* current_model = (Model*)GetListEntry(&world_reference->models, (z * world_reference->tiles_width) + x);

            int32_t bottom_z = z + 1;
            int32_t top_z = z - 1;
            int32_t left_x = x - 1;
            int32_t right_x = x + 1;
            int32_t top_y = 1;
            int32_t bottom_y = 0;

            int face_ids[6] = {0, 0, 0, 0, 0, 0};

            if (left_x >= 0)
                face_ids[2] = 1;

            if (right_x < world_reference->tiles_width)
                face_ids[1] = 1;

            if (top_z >= 0)
                face_ids[0] = 1;

            if (bottom_z < world_reference->tiles_depth)
                face_ids[3] = 1;

            UpdateProjectionMatrix(current_model, &projection);
            UpdateModelPosition(current_model);
            UpdateCameraPosition(current_model, world_reference->camera.position);
            UpdateColor(current_model, current_model->color);
            UpdateFaces(current_model, face_ids, 6);
            DrawModel(current_model);
        }
    }
}

void DeleteWorld(World *world) {
    DeleteListWithAllocations(&world->models);
}
