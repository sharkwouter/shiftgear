#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>

typedef struct {
    SDL_Rect rect;
    SDL_Texture* texture;
} Sprite;

Sprite spriteFromFile(char[]);
void drawSprite(Sprite);
void destroySprite(Sprite *);
#endif