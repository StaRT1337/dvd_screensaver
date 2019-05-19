#pragma once
#include "DVD.hpp"

class Screensaver
{
private:
	int screen_width_;
	int screen_height_;

	DVD dvd_;
public:
	Screensaver(const int screen_width, const int screen_height);
	~Screensaver();

	void run();
};
