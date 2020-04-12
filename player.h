#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"

typedef struct Player {
    int lane;
    Sprite sprite;
} Player;

Player createPlayer(SDL_Renderer*);
void movePlayer(Player*, int);
void drawPlayer(SDL_Renderer*, Player);
void destroyPlayer(Player*);
void printPlayer(Player*);

#endif // PLAYER_H
