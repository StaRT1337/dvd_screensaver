#include "stdinc.hpp"
#include "Screensaver.hpp"

Screensaver::Screensaver(const int screen_width, const int screen_height) : screen_width_(screen_width), screen_height_(screen_height), dvd_(screen_width_, screen_height_)
{
	InitWindow(screen_width_, screen_height_, "DVD Screensaver");
	SetTargetFPS(60);

	dvd_.load();
}

Screensaver::~Screensaver()
{
	CloseWindow();
}

void Screensaver::run()
{
	while (!WindowShouldClose())
	{
		dvd_.update();

		BeginDrawing();

		ClearBackground(BLACK);
		dvd_.draw();

		EndDrawing();
	}
}
