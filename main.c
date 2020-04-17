#include "game_state.h"
#include "game.h"

#ifdef PSP
#include <pspkernel.h>
PSP_MODULE_INFO("Shiftgear", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);
#endif

// int main(int argc, char** argv) {
int main() {
	GameState gameState = init();

	while (running) {
		handleEvents(&gameState);
		update();
		render(&gameState);
		SDL_Delay(1000/60);
	}

	return quit(&gameState);
}
