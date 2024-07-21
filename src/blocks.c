#include "blocks.h"
#include "raylib.h"

Model blockModels[NUM_BLOCKS];
Texture blockTextures[NUM_BLOCKS];

void InitBlocks()
{
	blockModels[BLOCK_GREEN] = LoadModel(MODEL_BLOCK_GREEN);
	blockTextures[BLOCK_GREEN] = LoadTexture(TEXTURE_BLOCK_GREEN);
	SetMaterialTexture(&blockModels[BLOCK_GREEN].materials[0], MATERIAL_MAP_DIFFUSE, blockTextures[BLOCK_GREEN]);
}

Block *NewBlock(unsigned int blockType)
{		
	Block *block = malloc(sizeof(Block));
	block->type = blockType;
	block->model = blockModels[blockType];
	block->texture = blockTextures[blockType];

	return block;
}

void DrawBlock(Block *block)
{
	DrawModel(block->model, block->position, 1.0f, WHITE);
}

void DestroyBlock(Block *block)
{
	UnloadTexture(block->texture);
	UnloadModel(block->model);
	free(block);
}
