#pragma once
#include "I8080/I8080.h"

FORCE_INLINE void I8080_SPHL(Memory &memory, I8080 &cpu) {
    cpu.SP = I8080::wordRegisterAsWordSwapped(cpu.H, cpu.L);
    cpu.cycles++;
}
