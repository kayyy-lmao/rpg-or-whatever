#include "blocks.h"
#include "raylib.h"
#include "world.h"
#include <stdio.h>

Model blockModels[NUM_BLOCKS];
Texture blockTextures[NUM_BLOCKS];

void InitBlocks()
{
	blockModels[BLOCK_GREEN] = LoadModel(MODEL_BLOCK_GREEN);
	blockTextures[BLOCK_GREEN] = LoadTexture(TEXTURE_BLOCK_GREEN);
	SetMaterialTexture(&blockModels[BLOCK_GREEN].materials[0], MATERIAL_MAP_DIFFUSE, blockTextures[BLOCK_GREEN]);

	// shouldn't ever be drawn
	blockModels[BLOCK_INVALID] = blockModels[BLOCK_GREEN];
	blockTextures[BLOCK_INVALID] = blockTextures[BLOCK_GREEN];
}

void AddBlockToWorld(World *world, Block *block, int x, int y, int z)
{
	world->blocks[x][y][z] = block;
}

Block *NewBlock(unsigned int blockType)
{		
	Block *block = malloc(sizeof(Block));
	block->type = blockType;
	block->model = blockModels[blockType];
	block->texture = blockTextures[blockType];

	return block;
}

void DrawBlock(Block *block, Vector3 position)
{
	if (block == NULL || block->type == BLOCK_INVALID)
	{
		return;
	}

	position.x *= BLOCK_SIZE
	position.y *= BLOCK_SIZE
	position.z *= BLOCK_SIZE

	DrawModel(block->model, position, 1.0f, WHITE);
}

void DestroyBlock(Block *block)
{
	UnloadTexture(block->texture);
	UnloadModel(block->model);
	free(block);
}
