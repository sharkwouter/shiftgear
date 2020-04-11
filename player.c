#include "player.h"
#include <stdio.h>

#define PLAYER_X 8

// This function uses the player's lane and the lane constants
void setPlayerY(Player *player){
    player->sprite.rect.y = ((player->lane-1) * LANE_WIDTH) + LANE_OFFSET;
}

Player createPlayer(){
    Player player;
    player.lane = 2;

    player.sprite = spriteFromFile(IMAGE_PLAYER);
    player.sprite.rect.h = 64;
    setPlayerY(&player);

    return player;
}

void movePlayer(Player *player, int movement) {
    int new_location = player->lane + movement;
    if (0 < new_location && new_location <= LANES) {
        player->lane = new_location;
        setPlayerY(player);
    }
}

void drawPlayer(Player player){
    renderSprite(player.sprite);
}

void destroyPlayer(Player *player) {
    destroySprite(&player->sprite);
}