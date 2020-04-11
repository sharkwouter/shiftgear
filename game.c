#include "game.h"
#include <stdio.h>
#include "constants.h"

#define GAME_NAME "Shiftgear"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

void loadMedia();

char running = 0;

SDL_Window* window = NULL;
SDL_Surface* background = NULL;

SDL_Rect playerRect;

SDL_Texture* carTexture = NULL;
Sprite carSprite;

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
    RENDERER = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    loadMedia();

    running = 1;
}

void loadMedia(){
    // Load background image
    background = SDL_LoadBMP("images/road.bmp");

    // Load car image
    carSprite = spriteFromFile("images/car.bmp");

    carSprite.rect.y = 100;
    carSprite.rect.x = 50;
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
    SDL_RenderClear(RENDERER);
    renderSprite(carSprite);
    SDL_RenderPresent(RENDERER);
}

int quit() {
    destroySprite(&carSprite);
    SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}