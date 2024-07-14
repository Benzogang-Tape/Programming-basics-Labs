#include "mdict.h"

int main(int argc, char* argv[]) {
	bool isInteractive{ false };

	if (argc == 2 and strcmp(argv[1], "i") == 0)
		isInteractive = true;
	if (isInteractive)
		return InteractiveMode();
	return DemoMode();
}
