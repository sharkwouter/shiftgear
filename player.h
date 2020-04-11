#include "sprite.h"

typedef struct {
    int x;
    int y;
    Sprite sprite;
} Player;

Player player;

Player createPlayer(int x, int y);
void movePlayer();
void printPlayer();