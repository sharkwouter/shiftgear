#include "sprite.h"

Sprite spriteFromFile(char location[]) {
    Sprite temp;

    SDL_Surface* surface = SDL_LoadBMP(location);
    if (surface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", location, SDL_GetError());
        exit(1);
    }
    temp.texture = SDL_CreateTextureFromSurface(RENDERER, surface);
    SDL_FreeSurface(surface);
    if (temp.texture == NULL) {
        printf("Unable to load texture for image %s! SDL Error: %s\n", location, SDL_GetError());
        exit(1);
    }

    SDL_QueryTexture(temp.texture, NULL, NULL, &temp.rect.w, &temp.rect.h);

    return temp;
}

void renderSprite(Sprite sprite) {
    SDL_RenderCopy(RENDERER, sprite.texture, NULL, &sprite.rect);
}

void destroySprite(Sprite *sprite) {
    SDL_DestroyTexture(sprite->texture);
}