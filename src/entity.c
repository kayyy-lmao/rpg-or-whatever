#include "entity.h"
#include <raylib.h>

Model entityModels[NUM_ENTITIES];
Texture entityTextures[NUM_ENTITIES];

void InitEntities()
{
	entityModels[ENTITY_PLAYER] = LoadModel(MODEL_ENTITY_PLAYER);
	// entityTextures[ENTITY_PLAYER] = LoadTexture(TEXTURE_ENTITY_PLAYER);
	// SetMaterialTexture(&entityModels[entity_GRASS].materials[0], MATERIAL_MAP_DIFFUSE, entityTextures[entity_GRASS]);
}

void UpdateEntity(Entity *entity)
{
	switch (entity->type)
	{
		case ENTITY_PLAYER:
			switch (entity->state)
			{
				case ENTITY_STATE_WALK:
					entity->animFrame++;

					if (entity->animFrame >= entity->anims[0].frameCount) 
					{
						// Reset animation frame for looping animations.
						entity->animFrame = 0;
					}

					UpdateModelAnimation(entity->model, entity->anims[0], entity->animFrame);
				break;
					
			}
		break;
	}
}

Entity *NewEntity(unsigned int entityType)
{		
	Entity *entity = malloc(sizeof(Entity));
	entity->type           = entityType;
	entity->state          = ENTITY_STATE_WALK;
	entity->model          = entityModels[entityType];
	entity->texture        = entityTextures[entityType];
	entity->animCount      = 0;
	entity->anims          = LoadModelAnimations("assets/models/entities/player.iqm", &entity->animCount);
	entity->animFrame      = 0;
	
	printf("ANIMATION NAME: %s\n", entity->anims[0].name);

	int count = sizeof(entity->anims)/sizeof(entity->anims[0]);


	printf("TOTAL ANIMATIONS: %d\n", count);

	return entity;
}

void SetEntityState(Entity *entity, unsigned int entityState)
{
	entity->state = entityState;
	entity->animFrame = 0;
}

void DrawEntity(Entity *entity, Vector3 position)
{
	if (entity == NULL || entity->type == ENTITY_INVALID)
	{
		return;
	}

	DrawModel(entity->model, position, 1.0f, BLACK);
}

void DestroyEntity(Entity *entity)
{
	UnloadTexture(entity->texture);
	UnloadModel(entity->model);
	free(entity);
}
