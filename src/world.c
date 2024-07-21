#include "world.h"
#include "blocks.h"

World *NewWorld()
{
	World *world = malloc(sizeof(World));
	world->blocks = malloc(WORLD_SIZE_X * sizeof(int*));
	for (int x=0; x<WORLD_SIZE_X; x++)
	{
		world->blocks[x] = malloc(WORLD_SIZE_Y * sizeof(int*));

		for (int y=0; y<WORLD_SIZE_Y; y++)
		{
			world->blocks[x][y] = malloc(WORLD_SIZE_Z * sizeof(int*));

		   for (int z=0; z<WORLD_SIZE_Z; z++)
			{
				world->blocks[x][y][z] = NewBlock(BLOCK_INVALID);
			}
		}
	}

	return world;
}

void DrawWorld(World *world, Vector3 worldPosition)
{
	for (int x = 0; x < WORLD_SIZE_X; x++)
	{
		for (int y = 0; y < WORLD_SIZE_Y; y++)
		{
			for (int z = 0; z < WORLD_SIZE_Z; z++)
			{
				DrawBlock(world->blocks[x][y][z], (Vector3){
					worldPosition.x + x,
					worldPosition.y + y,
					worldPosition.z + z,
			  });
			}
		}
	}
}

void DestroyWorld(World *world)
{
	for (int x = 0; x < WORLD_SIZE_X; x++)
	{
		for (int y = 0; y < WORLD_SIZE_Y; y++)
		{
			for (int z = 0; z < WORLD_SIZE_Z; z++)
			{
				DestroyBlock(world->blocks[x][y][z]);
			}
		}
	}

	free(world->blocks);
	free(world);
}
