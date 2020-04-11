#include "game.h"
#include <stdio.h>

#define GAME_NAME "Shiftgear"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272


void loadMedia();

char running = 0;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* background = NULL;

SDL_Rect playerRect;

SDL_Texture* carTexture = NULL;

SDL_Event event;

void init(){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    loadMedia();

    running = 1;
}

void loadMedia(){
    // Load background image
    background = SDL_LoadBMP("image.bmp");
    if (background == NULL) {
        printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Load car image
    SDL_Surface* carSurface = NULL;
    carSurface = SDL_LoadBMP("images/car.bmp");
    if (carSurface == NULL) {
        printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
    carTexture = SDL_CreateTextureFromSurface(renderer, carSurface);
    SDL_FreeSurface(carSurface);
    if (carTexture == NULL) {
        printf("Unable to load car texture! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }

    playerRect.y = 100;
    playerRect.x = 50;
    SDL_QueryTexture(carTexture, NULL, NULL, &playerRect.w, &playerRect.h);
    playerRect.x = 0;
}

void handleEvents(){
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = 0;
        }
        else if (event.type == SDL_KEYDOWN) {
            printf("Something is happening!\n");
            switch( event.key.keysym.sym ) {
                case SDLK_w:
                    printf("w\n");
                    break;
            }
        }
    }
}
void update(){}

void render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, carTexture, NULL, &playerRect);
    SDL_RenderPresent(renderer);
}

int quit() {
    SDL_DestroyTexture(carTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}