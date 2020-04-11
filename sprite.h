#include <SDL2/SDL.h>

typedef struct {
    SDL_Rect rect;
    SDL_Texture* texture;
} Sprite;

Sprite spriteFromFile(char[]);
void renderSprite(Sprite);
void destroySprite(Sprite *);