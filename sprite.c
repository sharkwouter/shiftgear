#include "sprite.h"

Sprite spriteFromFile(SDL_Renderer* renderer, const char* location) {
    Sprite temp;

    SDL_Surface* surface = SDL_LoadBMP(location);
    if (surface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", location, SDL_GetError());
        exit(1);
    }
    temp.texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (temp.texture == NULL) {
        printf("Unable to load texture for image %s! SDL Error: %s\n", location, SDL_GetError());
        exit(1);
    }

    SDL_QueryTexture(temp.texture, NULL, NULL, &temp.rect.w, &temp.rect.h);

    // TODO: Change this later
    temp.rect.x = 150;
    temp.rect.y = 150;

    return temp;
}

void drawSprite(SDL_Renderer* renderer, Sprite sprite) {
    SDL_RenderCopy(renderer, sprite.texture, NULL, &sprite.rect);
}

void destroySprite(Sprite* sprite) {
    SDL_DestroyTexture(sprite->texture);
}
