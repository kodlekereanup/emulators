#ifndef MOS6502_H
#define MOS6502_H

#include <stdint.h>
#include <stdbool.h>

// Forward declaration to avoid cyclical declarations 
struct Bus;

struct mos6502 {

    struct Bus* bus; // = NULL but you can't do that

    // Connect CPU and Bus
    void    (*connectCPUAndBus)(struct mos6502, struct Bus*);
    uint8_t (*read)(const uint16_t addr); // TODO: map these to bus.h read 
    void    (*write)(uint16_t addr, uint8_t data); // TODO: map this to bus.h write 

    /*
     * enum representing the avaiable flags in the 6502.
     * It an 8-bit status register which stores the statuses
     * of all the flags
     * */
    enum FLAGS {
        C = (1 << 0),       // Carry Flag 
        Z = (1 << 1),       // Zero Flag
        I = (1 << 2),       // Interrupt Flag
        D = (1 << 3),       // Decimal Mode
        B = (1 << 4),       // Break Flag
        U = (1 << 5),       // Unused Bit
        O = (1 << 6),       // Overflow Flag
        N = (1 << 7)        // Negative Flag
    };

    // Registers //
    uint8_t  a;             // Accumulator
    uint8_t  x;             // X register
    uint8_t  y;             // Y register
    uint8_t  stkp;          // Stack Pointer
    uint16_t pc;            // Program Counter
    uint8_t  status;        // Status Register

};

uint8_t read(const uint16_t addr) { 
    struct Bus* bus;
    bus->read(bus, addr, false);
}

void write(uint16_t addr, uint8_t data) { 
    struct Bus* bus;
    bus->write(bus, addr, data);
}

void mos6502_constructor(struct mos6502* cpu) {
    cpu->read = read;
    cpu->write = write;
}

// Function definition for connectBusToCPU() //
void connectBus(struct mos6502 cpu, struct Bus* b) { cpu.bus = b; }

//uint8_t read(struct Bus* bus, uint16_t addr) { return bus->read(bus, addr, false); }

//void write(struct Bus* bus, uint16_t addr, uint8_t data) { bus->write(bus, addr, data); }

#endif 