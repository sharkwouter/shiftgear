#include <stdio.h>
#include "game.h"
#include "constants.h"
#include "player.h"
#include "background.h"

void loadMedia();

char running = 0;

GameState init() {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    GameState gameState;

    gameState.window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gameState.window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    gameState.renderer = SDL_CreateRenderer(gameState.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    loadMedia(&gameState);

    gameState.state = PLAYING_STATE; // TODO: Change this later

    running = 1;
    return gameState;
}

void loadMedia(GameState* gameState) {
    // Load background image
    createBackground(gameState->renderer, gameState->background, BACKGROUND_TILES);

    gameState->player = createPlayer(gameState->renderer);
}

void handleEvents(GameState* gameState) {
    while (SDL_PollEvent(&gameState->event)) {
        if (gameState->event.type == SDL_QUIT) {
            running = 0;
        } else if (gameState->event.type == SDL_KEYDOWN) {
            switch(gameState->event.key.keysym.sym) {
            case SDLK_w:
                break;
            case SDLK_a:
                break;
            case SDLK_UP:
                break;
            case SDLK_LEFT:
                movePlayer(&gameState->player, -1);
                break;
            case SDLK_s:
                break;
            case SDLK_d:
                break;
            case SDLK_DOWN:
                break;
            case SDLK_RIGHT:
                movePlayer(&gameState->player, 1);
                break;
            }
        }
    }
}

void update() {}

void render(GameState* gameState) {
    SDL_RenderClear(gameState->renderer);
    drawBackground(gameState->renderer, gameState->background, BACKGROUND_TILES);
    drawPlayer(gameState->renderer, gameState->player);
    SDL_RenderPresent(gameState->renderer);
}

int quit(GameState* gameState) {
    destroyPlayer(&gameState->player);
    SDL_DestroyRenderer(gameState->renderer);
    SDL_DestroyWindow(gameState->window);
    SDL_Quit();

    return 0;
}
