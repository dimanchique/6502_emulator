#pragma once
#include "Types.h"

struct CPU6502;
struct Memory;

void CPU6502_ROR_ACC(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ROR_ZP(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ROR_ZPX(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ROR_ABS(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ROR_ABSX(U32 &Cycles, Memory &memory, CPU6502 &cpu);