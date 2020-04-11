#include "sprite.h"

typedef struct {
    int lane;
    Sprite sprite;
} Player;

Player createPlayer();
void movePlayer(Player *, int);
void drawPlayer(Player *);
void destroyPlayer(Player *);
void printPlayer(Player *);

extern int LANES;
extern int LANE_WIDTH;
extern int LANE_OFFSET;
extern char IMAGE_PLAYER[];