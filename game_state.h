#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "constants.h"
#include "sprite.h"
#include "player.h"

typedef enum {
    MENU_STATE,
    PLAYING_STATE
} State;

typedef struct GameState {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    State state;

    Sprite background[BACKGROUND_TILES];
    Player player;
} GameState;

#endif // GAME_STATE_H
