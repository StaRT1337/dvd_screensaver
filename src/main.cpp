#include "stdinc.hpp"
#include "Screensaver.hpp"

auto main() -> int
{
	Screensaver screensaver(1000, 750);
	screensaver.run();

	return 0;
}
