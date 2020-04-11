#include "sprite.h"

typedef struct {
    int lane;
    Sprite sprite;
} Player;

Player createPlayer();
void movePlayer(Player *, int);
void drawPlayer(Player);
void destroyPlayer(Player *);
void printPlayer(Player *);

extern const int LANES;
extern const int LANE_WIDTH;
extern const int LANE_OFFSET;
extern char IMAGE_PLAYER[];