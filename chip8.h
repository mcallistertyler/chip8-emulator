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
    // SE Vx - Skip next instruction if Vx == kk
    void OP_3xkk();
    // SNE Vx - Skip next instruction if Vx != kk
    void OP_4xkk();
    // SE Vx, Vy - Skip next instrucion if Vx = Vy
    void OP_5xy0();
    // LD Vx, byte - Set Vx = vk
    void OP_6xkk();
    // ADD Vx, byte - Set Vx = Vx + kk
    void OP_7xkk();
    // LD Vx, Vy - Set Vx = Vy
    void OP_8xy0();
    // OR Vx, Vy - Set Vx = Vx OR Vy
    void OP_8xy1();
    // AND Vx, Vy - Set Vx = Vx AND Vy
    void OP_8xy2();
    // XOR Vx, Vy - Set Vx = Vx OR Vy
    void OP_8xy3();
    // ADD Vx, Vy - Set Vx = Vx + Vy, set VF = carry
    void OP_8xy4();
    // SUB Vx, Vy - Set Vx = Vx - Vy, set VF = NOT borrow
    void OP_8xy5();
    // SHR Vx {, Vy} - Set Vx = Vx SHR 1
    void OP_8xy6();
    // SUBN Vx, Vy Set Vx = Vy - Vx, set VF = NOT borrow.
    void OP_8xy7();
    // SHL Vx {, Vy} - Set Vx SHL 1
    void OP_8xyE();
    // SNE Vx, Vy - Skip next instruction if Vx != Vy
    void OP_9xy0();
    // LD I, addr - Set I = nnn
    void OP_Annn();
    // JP V0, addr - Jump to location nnn + V0
    void OP_Bnnn();
    // RND Vx, byte - Set Vx = random byte AND kk.
    void OP_Cxkk();
    // DRW Vx, Vy, nibble - Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
    void OP_Dxyn();
};

#endif // CHIP8_H
