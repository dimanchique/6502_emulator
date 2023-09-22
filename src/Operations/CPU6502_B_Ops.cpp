#include "Operations/CPU6502_B_Ops.h"
#include "CPU6502.h"
#include "Memory.h"

void CPU6502_B_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu, BYTE TargetFlag, bool ExpectedValue){
    const SBYTE Offset = cpu.FetchByte(Cycles, memory);
    if(TargetFlag == ExpectedValue){
        CPU6502::DoTick(Cycles);
        if(isPageCrossed(cpu.PC, cpu.PC + Offset))
            CPU6502::DoTick(Cycles);
        cpu.PC += Offset;
    }
}

void CPU6502_BCC_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu){
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.C, false);
}

void CPU6502_BCS_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu){
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.C, true);
}

void CPU6502_BEQ_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu){
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.Z, true);
}

void CPU6502_BNE_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu){
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.Z, false);
}

void CPU6502_BMI_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu) {
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.N, true);
}

void CPU6502_BPL_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu) {
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.N, false);
}

void CPU6502_BVC_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu) {
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.V, false);
}

void CPU6502_BVS_REL(U32 &Cycles, Memory &memory, CPU6502 &cpu) {
    CPU6502_B_REL(Cycles, memory, cpu, cpu.Status.V, true);
}