#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

typedef struct Sprite {
    SDL_Rect rect;
    SDL_Texture* texture;
} Sprite;

Sprite spriteFromFile(SDL_Renderer*, const char*);
void drawSprite(SDL_Renderer*, Sprite);
void destroySprite(Sprite*);

#endif // SPRITE_H
