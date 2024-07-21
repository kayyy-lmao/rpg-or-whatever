#pragma once
#include <raylib.h>
#include <stdlib.h>

#include "rpg.h"

#define BLOCKS_PATH MODELS_PATH "blocks/"

#define MODEL_BLOCK_GREEN BLOCKS_PATH "green/blockGreen.obj"
#define TEXTURE_BLOCK_GREEN BLOCKS_PATH "green/blockGreen.png"

#define BLOCK_SIZE 2.0f;

typedef enum {
	BLOCK_INVALID,
	BLOCK_GREEN,
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
