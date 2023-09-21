#pragma once
#include "Types.h"

struct CPU6502;
struct Memory;

void CPU6502_ASL_ACC(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ASL_ZP(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ASL_ZPX(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ASL_ABS(U32 &Cycles, Memory &memory, CPU6502 &cpu);
void CPU6502_ASL_ABSX(U32 &Cycles, Memory &memory, CPU6502 &cpu);