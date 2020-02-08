//
// Created by jeremiahkorreck on 2/8/20.
//

#include "Chip8.h"
#include <iostream>

Chip8::Chip8() {
    bool success = initSDL2();
    if(success) {
        std::cout << "SDL initialized,  initializing display surface" << std::endl;
        myDisplay = Display();
        myDisplay.Init(EMU_WIDTH,EMU_HEIGHT,0xffffffff, 0x00000000, window);
        std::cout << "display initialized" << std::endl;
    } else {
        std::cout << "SDL did not initialize properly" << std::endl;
        exit(-1);
    }
}

Chip8::~Chip8() {

}

void Chip8::processOpCode() {
    unsigned short opcode = (memory[PC] << 8) | memory[PC+1];
    std::cout << std::hex << "Opcode:   " << opcode << std::endl;
    switch (opcode & 0x000F) {
        case 0x8000:
            switch(opcode & 0x000F) {

                case 0x0000: //8XY0: Sets VX to the value of VY.
                    break;
                default:
                    std::cout << std::hex << "Unsupported OpCode: " << opcode << std::endl;
                    exit(-1);
            }
            std::cout << "Reached first switch" << std::endl;
            break;
        default:
            std::cout << std::hex << "Unsupported OpCode: " << opcode << std::endl;
            exit(-1);
    }

}

bool Chip8::initSDL2()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, EMU_WIDTH, EMU_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
    }

    return success;
}