#include "player.h"
#include <stdio.h>

Player createPlayer(int x, int y){
    Player player;
    player.x = x;
    player.y = y;

    player.sprite = spriteFromFile("images/car.bmp");

    return player;
}


void movePlayer(int x, int y) {
    player.x += x;
    player.y += y;
}

void printPlayer() {
    printf("%d, %d\n", player.x, player.y);
}