#include <stdint-gcc.h>
#include "List.h"
#include "Model.h"
#include "Camera.h"

typedef struct World {
    uint32_t tiles_width;
    uint32_t tiles_depth;
    List models;
    Camera camera;
} World;

World CreateWorld(uint32_t width, uint32_t height);

void AddWorldTile(World *world_reference, Model *model_reference);

void UpdateWorld(World *world_reference);

void DrawWorld(World *world_reference);

void DeleteWorld(World *world);