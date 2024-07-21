#include "blocks.h"

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "my rpg");

	Camera camera = { 0 };
	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	InitBlocks();

	Block *block = NewBlock(BLOCK_GREEN);
	block->position = (Vector3){ 0.0f, 0.0f, 0.0f };

	DisableCursor();
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		UpdateCamera(&camera, CAMERA_FIRST_PERSON);

		BeginDrawing();	

			ClearBackground(RAYWHITE);

			BeginMode3D(camera);
				DrawBlock(block);
				DrawGrid(10, 1.0f);
			EndMode3D();

		EndDrawing();
	}

	DestroyBlock(block);
	CloseWindow();

	return 0;
}
