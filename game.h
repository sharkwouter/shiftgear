#include <SDL2/SDL.h>
#include <stdio.h>
#include "player.h"

char running;

void init();
void handleEvents();
void update();
void render();
int quit();

extern char IMAGE_BACKGROUND[];
extern SDL_Renderer* RENDERER;