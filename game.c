#include "game.h"
#include "constants.h"

void loadMedia();

char running = 0;

SDL_Window* window = NULL;

const int backgroundTiles = 8;
Sprite background[8];
Player player;

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
    createBackground(background, backgroundTiles);

    player = createPlayer();
}

void handleEvents(){
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = 0;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch( event.key.keysym.sym ) {
                case SDLK_w:
                case SDLK_a:
                case SDLK_UP:
                case SDLK_LEFT:
                    movePlayer(&player, -1);
                    break;
                case SDLK_s:
                case SDLK_d:
                case SDLK_DOWN:
                case SDLK_RIGHT:
                    movePlayer(&player, 1);
                    break;
            }
        }
    }
}
void update(){}

void render(){
    SDL_RenderClear(RENDERER);
    drawBackground(background);
    drawPlayer(player);
    SDL_RenderPresent(RENDERER);
}

int quit() {
    destroyPlayer(&player);
    SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}