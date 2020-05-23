#ifndef BUS_H
#define BUS_H
#endif

#include "mos6502.h"
#include <stdint.h>
#include <stdbool.h>

// TODO: Learn to use header guards //
//#include <stdio.h>
#define RAM_SIZE 64 * 1024

struct Bus {
    struct mos6502 cpu;
    uint8_t ram[RAM_SIZE];
    
    bool (*write)(struct Bus*, const uint16_t addr, uint8_t data);
    uint8_t (*read)(const struct Bus*, const uint16_t addr, bool readOnly);
};

/*
 * Reads from the bus and writes the data into the RAM 
 * For the time being, returns a true if function succesfully 
 * writes the data, false otherwise. 
 * If address is not valid (not in range), function returns 204. (?)
 */
bool write(struct Bus* bus, const uint16_t addr, uint8_t data) {
    if(addr >= 0x0000 && addr <= 0xFFFF) {
        bus->ram[addr] = data;
        return true;
    } 
    // else printf("\n [ERROR]: Write Aborted. Ram Index Out of Bounds \n");
    // How to log erros then?
    return false;
}

/*
 * Reads from the ram and places the data into the bus 
 * Returns the same
 * If address is not valid (not in range), function returns 204.
 */
uint8_t read(const struct Bus* bus, const uint16_t addr, bool readOnly) {
    return (addr >= 0x0000 && addr <= 0xFFFF)? bus->ram[addr] : 0x00;
}

void bus_constructor(struct Bus* bus) {
    // setting member functions to read and write functions
    bus->read = read;
    bus->write = write;

    // Connect CPU to communication bus
    // bus->cpu.connectBusAndCPU(bus->cpu, bus);
    bus->cpu.connectCPUAndBus = connectBus;

     // Clear RAM contents //
    for(int i = 0; i < RAM_SIZE; i++) bus->ram[i] = 0x00;
   
    //connectBus(bus->cpu, bus);
    bus->cpu.connectCPUAndBus(bus->cpu, bus);
}

void bus_destructor();