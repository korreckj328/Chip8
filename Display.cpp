//
// Created by jeremiahkorreck on 2/7/20.
//
#include <SDL2/SDL.h>
#include "Display.h"

Display::Display() {
    screen = NULL;
}

Display::~Display() {
    // if the screen isn't null,  call SDL_FreeSurface to clean up
    if (screen != NULL) {
        SDL_FreeSurface(screen);
    }
}

void Display::Init(unsigned int width, unsigned int height, unsigned int colorOn, unsigned int colorOff, SDL_Window *window) {
    // if the screen isn't null,  free it before we start initializing it
    if (this->screen != NULL) {
        SDL_FreeSurface(this->screen);
    }
    this->screen = SDL_GetWindowSurface(window);
    this->width = width;
    this->height = height;
    this->pixelWidth = this->width / CHIP8_ORIGINAL_DISPLAY_WIDTH;
    this->pixelHeight = this->height / CHIP8_ORIGINAL_DISPLAY_HEIGHT;
    this->colorOn = colorOn;
    this->colorOff = colorOff;
}

// clears the display
void Display::clear() {
    // turn all the pixels to off
    for (int i = 0; i < CHIP8_RESOLUTION; i++) {
        this->pixels[i] = false;
    }
}

void Display::SetPixel(unsigned short x, unsigned short y, bool on, bool XOR) {
    // Wrap around the pixels if they breach the screen coordinates
    if (x >= CHIP8_ORIGINAL_DISPLAY_WIDTH)
    {
        x -= CHIP8_ORIGINAL_DISPLAY_WIDTH;
    }

    if (y >= CHIP8_ORIGINAL_DISPLAY_HEIGHT)
    {
        y -= CHIP8_ORIGINAL_DISPLAY_HEIGHT;
    }

    // Set the pixel to either on or off based on the bool provided
    if (XOR)
    {
        this->pixels[(y * CHIP8_ORIGINAL_DISPLAY_WIDTH) + x] ^= on;
    }
    else
    {
        this->pixels[(y * CHIP8_ORIGINAL_DISPLAY_WIDTH) + x] = on;
    }
}

bool Display::GetPixel(unsigned short x, unsigned short y) {
    return this->pixels[y * CHIP8_ORIGINAL_DISPLAY_WIDTH + x];
}

void Display::drawPixel(unsigned short x, unsigned short y, bool on) {
    unsigned int* screenPixels = (unsigned int*)this->screen->pixels;
    unsigned int pixelColor;
    if(on) {
        pixelColor = this->colorOn;
    } else {
        pixelColor = this->colorOff;
    }
    unsigned short realX = x * pixelWidth;
    unsigned short realY = y * pixelHeight;
    for (unsigned int x1 = realX; x1 < realX + pixelWidth; x1++) {
        for (unsigned int y1 = realY; y1 < realY + pixelHeight; y1++) {
            screenPixels[(y1 * this->width) + x1] = pixelColor;
        }
    }
}

void Display::process(SDL_Window *window) {
    draw(window);
}

bool *Display::GetPixels() {
    return this->pixels;
}

void Display::draw(SDL_Window *window) {
    for (unsigned short x = 0; x < CHIP8_ORIGINAL_DISPLAY_WIDTH; x++) {
        for (unsigned short y = 0; y < CHIP8_ORIGINAL_DISPLAY_HEIGHT; y++) {
            bool pixel = this->pixels[(y * CHIP8_ORIGINAL_DISPLAY_WIDTH) + x];
            if (pixel) {
                drawPixel(x,y, true);
            } else {
                drawPixel(x,y, false);
            }
        }
    }
    SDL_UpdateWindowSurface(window);
}