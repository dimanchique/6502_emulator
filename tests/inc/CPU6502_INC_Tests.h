#pragma once
#include "CPU6502_TestingSuite.h"

class CPU6502_INCFixture : public CPU6502_TestFixture{
public:
    void INC_ZP_CanAffectValue(CPU6502_OpCodes OpCode, BYTE MemoryValue, BYTE OffsetValueRegister = 0);
    void INC_ABS_CanAffectValue(CPU6502_OpCodes OpCode, BYTE MemoryValue, BYTE OffsetValueRegister = 0);
    void INC_IMPL_CanAffectValue(CPU6502_OpCodes OpCode, BYTE& TargetRegister);
};