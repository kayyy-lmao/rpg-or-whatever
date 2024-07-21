#include "blocks.h"
#include "world.h"
#include <raymath.h>

#define CUBE_SIZE 2
#define CUBE_COLOR RED

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "my rpg");

	Vector3 worldPosition = (Vector3){
		(float)-WORLD_SIZE_X / 2,
		(float)-WORLD_SIZE_Y / 2,
		(float)-WORLD_SIZE_Z / 2
	};

	Camera camera = { 0 };
	camera.position =(Vector3){10, 10, 10};
	camera.target = (Vector3){ 0, 0, 0 };
	camera.up = (Vector3){ 0, 1, 0 };
	camera.fovy = 90.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	InitBlocks();

	DisableCursor();
	SetTargetFPS(60);

	World *world = NewWorld();
	Block *block;
	
	for (int x = 0; x < WORLD_SIZE_X; x++) {
		for (int z = 0; z < WORLD_SIZE_Y; z++) {
			printf("Adding block to world at %d,%d,%d\n", x, 0, z);
			block = NewBlock(BLOCK_GREEN);
			AddBlockToWorld(world, block, x, 0, z);
		}
	}

	while (!WindowShouldClose())
	{
		UpdateCamera(&camera, CAMERA_THIRD_PERSON);

		BeginDrawing();	

			ClearBackground(RAYWHITE);

			BeginMode3D(camera);
				DrawWorld(world, worldPosition);
				// DrawGrid(100, 1.0f);
			EndMode3D();

		EndDrawing();
	}

	// DestroyBlock(block);
	CloseWindow();

	return 0;
}
