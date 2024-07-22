#pragma once
#include <raylib.h>
#include <stdlib.h>

#include "rpg.h"

#define BLOCKS_PATH MODELS_PATH "blocks/"

#define MODEL_BLOCK_GRASS BLOCKS_PATH "block.obj"
#define TEXTURE_BLOCK_GRASS BLOCKS_PATH "grass.png"

#define MODEL_BLOCK_WATER BLOCKS_PATH "block.obj"
#define TEXTURE_BLOCK_WATER BLOCKS_PATH "water.png"

#define BLOCK_SIZE 2.0f;

typedef enum {
	BLOCK_INVALID,
	BLOCK_GRASS,
	BLOCK_WATER,
	NUM_BLOCKS
} BlockTypes;

typedef struct Block {
	unsigned int type;
	Model        model;
	Texture      texture;
} Block;


void   InitBlocks();
Block *NewBlock(unsigned int blockType);
void DrawBlock(Block *block, Vector3 position);
void DestroyBlock(Block *block);
