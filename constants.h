#ifndef CONSTANTS_LOADED
#define CONSTANTS_LOADED
#include <SDL2/SDL.h>

// PSP screensize
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 272;

// constants for where the lanes are on the y access
const int LANES = 4;
const int LANE_WIDTH = 64;
const int LANE_OFFSET = 8;

// Global renderer
SDL_Renderer* RENDERER;

enum state {
    menu = 0,
    playing = 1,
};

// Image locations
const char IMAGE_PLAYER[] = "images/car.bmp";
#endif