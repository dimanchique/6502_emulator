#include "MOS6502_TestingSuite.h"

class MOS6502_PFixture : public MOS6502_TestFixture {};

TEST_F(MOS6502_PFixture, PHA_IMPL_CanPushAccumulator) {
    // given:
    cpu.A = 0x42;
    mem[0xFFFC] = MOS6502_OpCodes::PHA_IMPL;

    cyclesExpected = 3;

    // when:
    cyclesPassed = cpu.Run(mem);

    // then:
    EXPECT_EQ(mem[cpu.StackPointerToAddress() + 1], 0x42);
    CheckCyclesCount();
}

TEST_F(MOS6502_PFixture, PHA_IMPL_CanPushAndPullAccumulator) {
    // given:
    cpu.A = 0x42;
    mem[0xFFFC] = MOS6502_OpCodes::PHA_IMPL;
    mem[0xFFFD] = MOS6502_OpCodes::TXA_IMPL;
    mem[0xFFFE] = MOS6502_OpCodes::PLA_IMPL;

    cyclesExpected = 3 + 2 + 4;

    // when:
    cyclesPassed = cpu.Run(mem);

    // then:
    EXPECT_EQ(cpu.A, 0x42);
    CheckCyclesCount();
}

TEST_F(MOS6502_PFixture, PHP_IMPL_CanPushStatusRegister) {
    // given:
    cpu.Status = 0x42;                      // just for test
    mem[0xFFFC] = MOS6502_OpCodes::PHP_IMPL;

    cyclesExpected = 3;

    // when:
    cyclesPassed = cpu.Run(mem);

    // then:
    EXPECT_EQ(mem[cpu.StackPointerToAddress() + 1], 0x42);
    CheckCyclesCount();
}

TEST_F(MOS6502_PFixture, PHP_IMPL_CanPushAndPullAccumulator) {
    // given:
    cpu.Status = 0x42;
    mem[0xFFFC] = MOS6502_OpCodes::PHP_IMPL;
    mem[0xFFFD] = MOS6502_OpCodes::PHA_IMPL;
    mem[0xFFFE] = MOS6502_OpCodes::PLP_IMPL;
    mem[0xFFFF] = MOS6502_OpCodes::PLA_IMPL;

    cyclesExpected = 3 + 3 + 4 + 4;

    // when:
    cyclesPassed = cpu.Run(mem);

    // then:
    EXPECT_EQ(cpu.A, 0x42);
    EXPECT_EQ(cpu.Status, 0x00);
    CheckCyclesCount();
}