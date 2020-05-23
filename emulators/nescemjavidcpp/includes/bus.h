/*
 * Bus class to represent the Bus that connects the devices
 * 
*/

#pragma once

#ifndef BUS_H
#define BUS_H

#include "../includes/mos6502.h"

#include <cstdint>
#include <array>

class Bus {

    public: // Devices connected on the Bus
    mos6502 cpu;
    std::array<uint8_t, 64 * 1024> ram;

    public: // Bus Class ctor and dtor
    Bus();
    ~Bus();

    public: // Bus Class Public Functions

/*
 * Reads from the bus and writes the data into the RAM 
 * For the time being, returns a true if function succesfully 
 * writes the data, false otherwise. 
 * If address is not valid (not in range), function returns 204. (?)
 */
    void write(const uint16_t& addr, const uint8_t& data);
   
/*
 * Reads from the ram and places the data into the bus 
 * Returns the same
 * If address is not valid (not in range), function returns 204.
 */
    uint8_t read(const uint16_t& addr, bool bReadOnly = false) const;

};

#endif