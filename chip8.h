#ifndef CHIP8_H
#define CHIP8_H
#include <cstdint>
#include <chrono>
#include <random>
#include <cstring>

class Chip8
{
public:
    uint8_t registers[16]{};
    uint8_t memory[4096]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack[16]{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint64_t soundTimer{};
    uint8_t keypad[16]{};
    uint32_t video[64 * 32]{};
    uint16_t opcode;
    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;

    Chip8();
    void LoadROM(char const* filename);

private:
    // CLS: set entire video buffer to zeroes
    void OP_00E0();
    // RET: return from a subroutine
    void OP_00EE();
    // JP addr - Jump to location nnn
    void OP_1nnn();
    // CALL addr - Call subroutine at nnn
    void OP_2nnn();
};

#endif // CHIP8_H
