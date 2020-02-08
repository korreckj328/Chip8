//
// Created by jeremiahkorreck on 2/8/20.
//

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H
#define CHIP8_TOTAL_MEMORY 4096
#define CHIP8_TOTAL_REGISTERS 16
#define EMU_WIDTH 640
#define EMU_HEIGHT 320

#include <SDL2/SDL.h>
#include "stack-jdk/stackArray.h"
#include "Display.h"

class Chip8 {
public:
    Chip8();
    ~Chip8();
    void processOpCode();

private:
    SDL_Window *window = nullptr;
    Display myDisplay;
    unsigned char memory[CHIP8_TOTAL_MEMORY];
    unsigned char V[CHIP8_TOTAL_REGISTERS];
    unsigned char I = 0x0;
    unsigned int PC = 0x200;
    unsigned char delayTimer = 0;
    unsigned char soundTimer = 0;
    unsigned char stackPointer = 0;
    unsigned char stack[16];
    unsigned char keys[16];
    bool displayArr[64 * 32];

    bool initSDL2();
};


#endif //CHIP8_CHIP8_H
