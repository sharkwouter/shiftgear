#include "background.h"

void createBackground(Sprite* tiles, const int tiles_amount) {
    SDL_Surface *surface = SDL_LoadBMP(IMAGE_BACKGROUND);
    if (surface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", IMAGE_BACKGROUND, SDL_GetError());
        exit(1);
    }

    for(int i = 0; i < tiles_amount; i++) {
        Sprite tile;
        tile.texture = SDL_CreateTextureFromSurface(RENDERER, surface);
        SDL_QueryTexture(tile.texture, NULL, NULL, &tile.rect.w, &tile.rect.h);
        tile.rect.x = i * tile.rect.w;
        tile.rect.y = 0;
        tiles[i] = tile;
    }

    SDL_FreeSurface(surface);
}

void drawBackground(Sprite* tiles[]) {
    int length = sizeof(tiles) / sizeof(Sprite);
    for(int i = 0; i < length; i++) {
        drawSprite(*tiles[i]);
    }
}