#include "background.h"
#include "constants.h"

void createBackground(SDL_Renderer* renderer, Sprite* tiles, const size_t numOfTiles) {
    SDL_Surface *surface = SDL_LoadBMP(IMAGE_BACKGROUND);
    if (surface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", IMAGE_BACKGROUND, SDL_GetError());
        exit(1);
    }

    for(size_t i = 0; i < numOfTiles; i++) {
        Sprite tile;
        tile.texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(tile.texture, NULL, NULL, &tile.rect.w, &tile.rect.h);
        tile.rect.x = i * tile.rect.w;
        tile.rect.y = 0;
        tiles[i] = tile;
    }

    SDL_FreeSurface(surface);
}

void drawBackground(SDL_Renderer* renderer, Sprite* tiles, size_t length) {
    for(size_t i = 0; i < length; i++) {
        drawSprite(renderer, tiles[i]);
    }
}
