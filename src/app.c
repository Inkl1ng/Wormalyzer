#include "app.h"

#include <stdio.h>
#include <raylib.h>
#include "skin.h"

void init_app()
{
	SetTraceLogLevel(LOG_NONE);
	InitWindow(1280, 720, "Wormalyzer");
	InitAudioDevice();
	// cap the frame rate to the max of the monitor
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
	load_skin();
}

void run_app()
{
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_W))
		{
			play_sound(DRUM_HIT_NORMAL);
		}

		BeginDrawing();
			ClearBackground(BLACK);

			DrawFPS(0, 0);

			draw_element(100, 100, SLIDER_SCORE_POINT);
		EndDrawing ();
	}
}

void close_app()
{
	CloseWindow();
	CloseAudioDevice();
}
