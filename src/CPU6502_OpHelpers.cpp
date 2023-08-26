#include <CPU6502_OpHelpers.h>
#include <Operations/CPU6502_LDA_Ops.h>
#include <Operations/CPU6502_LDX_Ops.h>
#include <Operations/CPU6502_LDY_Ops.h>
#include <CPU6502.h>
#include <Memory.h>

void CPU6502_NOOP(S32& Cycles, Memory &memory, CPU6502 &cpu){}

void CPU6502_JSR_ABS(S32& Cycles, Memory &memory, CPU6502 &cpu){
    WORD JumpAddress = cpu.FetchWord(Cycles, memory);
    cpu.WriteWord(Cycles, cpu.PC - 1, cpu.SP, memory);
    cpu.PC = JumpAddress;
    cpu.SP += 2;
    Cycles--;
}

void CPU6502_CLC_IMPL(S32& Cycles, Memory &memory, CPU6502 &cpu){
    cpu.C = 0;
    Cycles -= 2;
}

void CPU6502_CLD_IMPL(S32& Cycles, Memory &memory, CPU6502 &cpu){
    cpu.D = 0;
    Cycles -= 2;
}

void CPU6502_CLI_IMPL(S32& Cycles, Memory &memory, CPU6502 &cpu){
    cpu.I = 0;
    Cycles -= 2;
}

void CPU6502_CLV_IMPL(S32& Cycles, Memory &memory, CPU6502 &cpu){
    cpu.V = 0;
    Cycles -= 2;
}

void CPU6502_DEX_IMPL(S32& Cycles, Memory &memory, CPU6502 &cpu){
    cpu.X--;
    Cycles -= 2;
    cpu.LoadRegisterSetStatus(cpu.X);
}

void CPU6502_DEY_IMPL(S32& Cycles, Memory &memory, CPU6502 &cpu){
    cpu.Y--;
    Cycles -= 2;
    cpu.LoadRegisterSetStatus(cpu.Y);
}

using OpSignature = void (*)(S32 &,Memory &,CPU6502 &);
const static OpSignature Ops[] = {
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_JSR_ABS,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_DEY_IMPL,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDY_IM,
        CPU6502_LDA_INDX,
        CPU6502_LDX_IM,
        CPU6502_NOOP,
        CPU6502_LDY_ZP,
        CPU6502_LDA_ZP,
        CPU6502_LDX_ZP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDA_IM,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDY_ABS,
        CPU6502_LDA_ABS,
        CPU6502_LDX_ABS,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDA_INDY,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDY_ZPX,
        CPU6502_LDA_ZPX,
        CPU6502_LDX_ZPY,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDA_ABSY,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_LDY_ABSX,
        CPU6502_LDA_ABSX,
        CPU6502_LDX_ABSY,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_DEX_IMPL,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP,
        CPU6502_NOOP
};

BYTE FetchCommand(S32& Cycles, BYTE OpCode, Memory &Memory, CPU6502 &CPU) {
    Ops[OpCode](Cycles, Memory, CPU);
    return 1;
}