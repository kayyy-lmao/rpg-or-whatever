#pragma once

#include "blocks.h"
#include <raylib.h>
#include <stdlib.h>

#define WORLD_SIZE_X 64
#define WORLD_SIZE_Y 64
#define WORLD_SIZE_Z 64

typedef struct World {
	Block ****blocks;
} World;

World *NewWorld();
void AddBlockToWorld(World *world, Block *block, int x, int y, int z);
void DrawWorld(World *world, Vector3 worldPosition);
void DestroyWorld(World *world);
