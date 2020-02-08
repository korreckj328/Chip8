#include <iostream>
#include "Chip8.h"

int main() {
    Chip8 myChip = Chip8();
    myChip.processOpCode();
    return 0;
}
