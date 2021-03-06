#pragma once

#ifndef MOS6502_H
#define MOS6502_H

#include <string>
#include <vector>

// Forwards declaration of class Bus to avoid circular includes
class Bus;

//TODO: How to forard declare an enum
//enum FLAGS : char;

class mos6502 {

    public: // mos6502 Class ctor and dtor
    mos6502();
    ~mos6502();

    public: // Functionality

    /*
     * enum representing the avaiable flags in the 6502.
     * It an 8-bit status register which stores the statuses
     * of all the flags
     */
    enum FLAGS {
        C = (1 << 0),            // Carry Flag 
        Z = (1 << 1),            // Zero Flag
        I = (1 << 2),            // Interrupt Flag
        D = (1 << 3),            // Decimal Mode
        B = (1 << 4),            // Break Flag
        U = (1 << 5),            // Unused Bit
        O = (1 << 6),            // Overflow Flag
        N = (1 << 7)             // Negative Flag
    };

    // Registers //
    uint8_t  a      = 0x00;      // Accumulator
    uint8_t  x      = 0x00;      // X register
    uint8_t  y      = 0x00;      // Y register
    uint8_t  stkp   = 0x00;      // Stack Pointer
    uint16_t pc     = 0x0000;    // Program Counter
    uint8_t  status = 0x00;      // Status Register

    public: // mos6502 Class Public Functions
    void connectBus(Bus* n) { bus = n; }

    // Register Addressing Modes
    uint8_t IMP();  uint8_t IMM();
    uint8_t ZP0();  uint8_t ZPX();
    uint8_t ZPY();  uint8_t REL();
    uint8_t ABS();  uint8_t ABX();
    uint8_t ABY();  uint8_t IND();
    uint8_t IZX();  uint8_t IZY();

    // Opcodes 
    // There are 56 opcodes in the 6502 emulator 
    uint8_t ADC();  uint8_t AND();  uint8_t ASL();  uint8_t BCC();
    uint8_t BCS();  uint8_t BEQ();  uint8_t BIT();  uint8_t BMI();
    uint8_t BNE();  uint8_t BPL();  uint8_t BRK();  uint8_t BVC();
    uint8_t BVS();  uint8_t CLC();  uint8_t CLD();  uint8_t CLI();
    uint8_t CLV();  uint8_t CMP();  uint8_t CPX();  uint8_t CPY();
    uint8_t DEC();  uint8_t DEX();  uint8_t DEY();  uint8_t EOR();
    uint8_t INC();  uint8_t INX();  uint8_t INY();  uint8_t JMP();
    uint8_t JSR();  uint8_t LDA();  uint8_t LDX();  uint8_t LDY();
    uint8_t LSR();  uint8_t NOP();  uint8_t ORA();  uint8_t PHA();
    uint8_t PHP();  uint8_t PLA();  uint8_t PLP();  uint8_t ROL();
    uint8_t ROR();  uint8_t RTI();  uint8_t RTS();  uint8_t SBC();
    uint8_t SEC();  uint8_t SED();  uint8_t SEI();  uint8_t STA();
    uint8_t STX();  uint8_t STY();  uint8_t TAX();  uint8_t TAY();
    uint8_t TSX();  uint8_t TXA();  uint8_t TXS();  uint8_t TYA();

    uint8_t XXX(); // All illegal operations will be caught here 

    // Clock for the functioning of the CPU
    void clock();  

    // Asynchrounous Functions
    // resets the state of the CPU
    void reset();

    // Interrupt Request 
    void irq();

    // Non Maskable Inerrupt
    void nmi();

    uint8_t fetch() const;

    uint8_t  fetched      = 0x00;
    uint16_t addr_abs     = 0x0000;
    uint16_t addr_rel     = 0x0000;
    uint8_t  opcode       = 0x00;
    uint8_t  cycles       = 0x00;   // Remaining cycles the instruction has

    private:

    Bus* bus = nullptr;

    // mos6502 Class Private Functions
    // Calls the bus class functions internally 
    uint8_t read(const uint16_t&) const;
    void write(const uint16_t&, const uint8_t&);

    struct INSTRUCTION {
        std::string name;
        uint8_t (mos6502 :: *operate)(void) = nullptr;
        uint8_t (mos6502 :: *addr_mode)(void) = nullptr;
        uint8_t cycles = 0;
    };

    // Lookup Table 
    std::vector<INSTRUCTION> lookup;
    uint8_t getFlag(const FLAGS&) const;
    void setFlag(FLAGS, const bool&);

};

#endif