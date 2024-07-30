#pragma once

#include <raylib.h>
#include "rpg.h"

#define ENTITIES_PATH MODELS_PATH "entities/"

#define MODEL_ENTITY_PLAYER ENTITIES_PATH "player.iqm"
#define TEXTURE_ENTITY_PLAYER ENTITIES_PATH "player.png"

typedef struct Entity {
	unsigned int    type;
	unsigned int    state;
	ModelAnimation *anims;
	int             animCount;
	int             animFrame;
	Model           model;
	Texture         texture;
} Entity;

typedef enum EntityTypes {
	ENTITY_INVALID,
	ENTITY_PLAYER,
	NUM_ENTITIES
} EntityTypes;

typedef enum EntityStates {
	ENTITY_STATE_STAND,
	ENTITY_STATE_WALK,
} EntityStates;

void InitEntities();
Entity *NewEntity(unsigned int entityType);
void SetEntityState(Entity *entity, unsigned int entityState);
void UpdateEntity(Entity *entity);
void DrawEntity(Entity *entity, Vector3 position);
void DestroyEntity(Entity *entity);
