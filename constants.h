#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SDL2/SDL.h>

// PSP screensize
#define GAME_NAME "Shiftgear"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

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
char IMAGE_PLAYER[] = "images/car.bmp";
char IMAGE_BACKGROUND[] = "images/road.bmp";
#endif