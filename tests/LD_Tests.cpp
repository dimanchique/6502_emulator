#include "CPU6502_LD_Tests.h"

void CPU6502_LDFixture::LD_IM_CanLoadValue(CPU6502_OpCodes OpCode, BYTE& TargetRegister){
    // given:
    BYTE OldValue = 0x44;
    BYTE NewValue = 0x04;
    TargetRegister = OldValue;
    mem[0xFFFC] = OpCode;                                       // read value from the next mem cell
    mem[0xFFFD] = NewValue;                                     // store this value in target register

    // when:
    cpu.Run(2, mem);

    // then:
    EXPECT_NE(TargetRegister, OldValue);
    EXPECT_EQ(TargetRegister, NewValue);
}

void CPU6502_LDFixture::LD_IM_CanAffectZeroFlag(CPU6502_OpCodes OpCode){
    // given:
    mem[0xFFFC] = OpCode;                                       // read value from the next mem cell
    mem[0xFFFD] = 0x0;                                          // store this value in target register

    // when:
    cpu.Run(2, mem);

    // then:
    EXPECT_TRUE(cpu.Z);
    EXPECT_FALSE(cpu.N);
}

void CPU6502_LDFixture::LD_IM_CanAffectNegativeFlag(CPU6502_OpCodes OpCode){
    // given:
    mem[0xFFFC] = OpCode;                                       // read value from the next mem cell
    mem[0xFFFD] = 0x80;                                         // store this value in target register

    // when:
    cpu.Run(2, mem);

    // then:
    EXPECT_FALSE(cpu.Z);
    EXPECT_TRUE(cpu.N);
}

void CPU6502_LDFixture::LD_ZP_CanLoadValue(CPU6502_OpCodes OpCode, BYTE& TargetRegister){
    // given:
    mem[0xFFFC] = OpCode;                                       // read pointer to the ZP memory from the next mem cell
    mem[0xFFFD] = 0x42;                                         // read value from memory using pointer
    mem[0x0042] = 0x37;                                         // store this value in target register

    const U32 NumCycles = 3;

    // when:
    U32 CNT = cpu.Run(NumCycles, mem);

    // then:
    EXPECT_EQ(TargetRegister, 0x37);
    EXPECT_FALSE(cpu.Z);
    EXPECT_FALSE(cpu.N);
    EXPECT_EQ(CNT, NumCycles);
}

void CPU6502_LDFixture::LD_ZP_CanLoadValue(CPU6502_OpCodes OpCode, BYTE& TargetRegister, BYTE AffectingRegister){
    // given:
    mem[0xFFFC] = OpCode;                                       // read pointer to the ZP memory from the next mem cell
    mem[0xFFFD] = 0x42;                                         // add AffectingRegister value to this pointer
    mem[(mem[0xFFFD] + AffectingRegister) & 0xFF] = 0x37;       // read value from memory using pointer
                                                                // store this value in TargetRegister register
    const U32 NumCycles = 4;

    // when:
    U32 CNT = cpu.Run(NumCycles, mem);

    // then:
    EXPECT_EQ(TargetRegister, 0x37);
    EXPECT_FALSE(cpu.Z);
    EXPECT_FALSE(cpu.N);
    EXPECT_EQ(CNT, NumCycles);
}

void CPU6502_LDFixture::LD_ABS_CanLoadValue(CPU6502_OpCodes OpCode, BYTE& TargetRegister){
    // given:
    mem[0xFFFC] = OpCode;                       // read the 16 bit Little Endian pointer from the next mem cell
    mem[0xFFFD] = 0x80;                         // read from this address
    mem[0xFFFE] = 0x44;                         // 0x4480
    mem[0x4480] = 0x37;                         // store this value in TargetRegister

    const S32 NumCycles = 4;

    // when:
    U32 CNT = cpu.Run(NumCycles, mem);

    // then:
    EXPECT_EQ(TargetRegister, 0x37);
    EXPECT_FALSE(cpu.Z);
    EXPECT_FALSE(cpu.N);
    EXPECT_EQ(CNT, NumCycles);
}

void CPU6502_LDFixture::LD_ABS_CanLoadValue(CPU6502_OpCodes OpCode, BYTE& TargetRegister, BYTE AffectingRegister){
    // given:
    mem[0xFFFC] = OpCode;                       // read the 16 bit Little Endian pointer from the next mem cell
    mem[0xFFFD] = 0x02;                         // read from this address
    mem[0xFFFE] = 0x44;                         // target value is in memory address 0x4402 + AffectingRegister
    mem[0x4402 + AffectingRegister] = 0x37;     // store this value in TargetRegister

    const S32 NumCycles = (0x4402 + AffectingRegister) - 0x4402 >= 0xFF ? 5 : 4;

    // when:
    U32 CNT = cpu.Run(NumCycles, mem);

    // then:
    EXPECT_EQ(TargetRegister, 0x37);
    EXPECT_FALSE(cpu.Z);
    EXPECT_FALSE(cpu.N);
    EXPECT_EQ(CNT, NumCycles);
}