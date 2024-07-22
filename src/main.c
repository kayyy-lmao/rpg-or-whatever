#include "blocks.h"
#include "world.h"
#include <raylib.h>
#include <raymath.h>

#define CAMERA_SPEED 0.5f
#define CAMERA_DISTANCE 10

int main(void)
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "my rpg");

	Vector3 worldPosition = {
		-WORLD_SIZE_X/2.0,
		-WORLD_SIZE_Y/2.0,
		-WORLD_SIZE_Z/2.0,
	};

	Camera camera = { 0 };
	camera.position   = (Vector3){10, 10, WORLD_SIZE_X};
	camera.target     = (Vector3){ 0, 0, 0 };
	camera.up         = (Vector3){ 0, 1, 0 };
	camera.fovy       = 90.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	float camera_mag = CAMERA_DISTANCE;
	float alpha      = 0.0;
	float beta       = 0.0;

	InitBlocks();

	DisableCursor();
	SetTargetFPS(60);

	World *world = NewWorld();
	Block *block;
	
	for (int x = 0; x < WORLD_SIZE_X; x++) {
		for (int z = 0; z < WORLD_SIZE_Y; z++) {
			block = NewBlock(BLOCK_GRASS);
			AddBlockToWorld(world, block, x, 0, z);
		}
	}

	// add some water as a test.
	for (int x = 20; x < 40; x++) {
		for (int z = 30; z < 60; z++) {
			block = NewBlock(BLOCK_WATER);
			AddBlockToWorld(world, block, x, 0, z);
		}
	}

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		
        // Camera PRO usage example (EXPERIMENTAL)
        // This new camera function allows custom movement/rotation values to be directly provided
        // as input parameters, with this approach, rcamera module is internally independent of raylib inputs
        UpdateCameraPro(&camera,
            (Vector3){
                (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*CAMERA_SPEED -      // Move forward-backward
                (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*CAMERA_SPEED,    
                (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*CAMERA_SPEED -   // Move right-left
                (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*CAMERA_SPEED,
                0.0f                                                // Move up-down
            },
            (Vector3){
                GetMouseDelta().x*0.05f,                            // Rotation: yaw
                GetMouseDelta().y*0.05f,                            // Rotation: pitch
                0.0f                                                // Rotation: roll
            },
            GetMouseWheelMove()*-2.0f);                              // Move to target (zoom)

		// UpdateCamera(&camera, CAMERA_THIRD_PERSON);

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
