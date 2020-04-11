#include "constants.h"
#include "game.h"

int main(int argc, char* args[]) {
	init();

	while (running) {
		handleEvents();
		update();
		render();
		SDL_Delay(1000/60);
	}

	return quit();
}
