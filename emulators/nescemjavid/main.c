#include <stdio.h>
#include "includes/bus.h"
#include "includes/mos6502.h"

// TODO:
// Create a makefile
// gcc flags
// logger system
// header guards
void main(int argc, char** argv) {
    printf("Hello World!");

    struct Bus* bus;
    // In OOP, this should call cpu.connectBus(this) //
    connectBus(bus->cpu, bus);


}
