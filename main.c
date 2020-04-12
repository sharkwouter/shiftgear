#include "game_state.h"
#include "game.h"

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
