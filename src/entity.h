#pragma once

#include <raylib.h>

#define ENTITIES_PATH MODELS_PATH "entities/"

#define MODEL_ENTITY_PLAYER ENTITIES_PATH "TPose_Character01.fbx"
#define TEXTURE_ENTITY_PLAYER ENTITIES_PATH ""

typedef struct Entity {
	unsigned int type;
	Model        model;
	Texture      texture;
} Entity;

typedef enum {
	ENTITY_INVALID,
	ENTITY_PLAYER,
	NUM_ENTITIES
} BlockTypes;
