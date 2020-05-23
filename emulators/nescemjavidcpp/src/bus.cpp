#include "../includes/bus.h"

Bus :: Bus() {
    // Clear the RAM upon instantiation
    for(auto& i : ram) i = 0x00;

    // Connect CPU to communication  bus
    cpu.connectBus(this);
}

Bus :: ~Bus() {

}

void Bus :: write(const uint16_t& addr, const uint8_t& data) {
    if(addr >= 0x00 && addr <= 0xFFFF) 
        ram[addr] = data;
}

uint8_t Bus :: read(const uint16_t& addr, bool bReadonly) const {
    return (addr >= 0x00 && addr <= 0xFFFF)? ram[addr] : 0x00;
}