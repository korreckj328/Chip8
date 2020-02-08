//
// Created by jeremiahkorreck on 2/7/20.
//

#ifndef CHIP8_DISPLAY_H
#define CHIP8_DISPLAY_H
#define CHIP8_ORIGINAL_DISPLAY_WIDTH 64
#define CHIP8_ORIGINAL_DISPLAY_HEIGHT 32
#define CHIP8_RESOLUTION CHIP8_ORIGINAL_DISPLAY_WIDTH * CHIP8_ORIGINAL_DISPLAY_HEIGHT



#include <SDL2/SDL.h>

class Display {
public:
    Display();
    ~Display();
    void Init(unsigned int width, unsigned int height, unsigned int colorOn, unsigned int colorOff, SDL_Window *window);
    void process(SDL_Window *window);
    bool* GetPixels();
    void SetPixel(unsigned short x, unsigned short y, bool on, bool XOR = false);
    bool GetPixel(unsigned short x, unsigned short y);
    void clear();
private:
    void draw(SDL_Window *window);
    void drawPixel(unsigned short x, unsigned short y, bool on);

    SDL_Surface *screen;
    unsigned int width;
    unsigned int height;
    unsigned short pixelWidth;
    unsigned short pixelHeight;
    unsigned int colorOn;
    unsigned int colorOff;
    bool pixels[CHIP8_RESOLUTION];
};


#endif //CHIP8_DISPLAY_H
