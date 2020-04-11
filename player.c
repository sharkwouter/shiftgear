#include "player.h"
#include <stdio.h>

Player player;

void movePlayer(int x, int y) {
    player.x += x;
    player.y += y;
}

void printPlayer() {
    printf("%d, %d\n", player.x, player.y);
}