#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "game_state.h"

char running;

GameState init();
void handleEvents(GameState* gameState);
void update();
void render(GameState* gameState);
int quit(GameState* gameState);

#endif // GAME_H
