#include "CPU6502_ASMTestingSuite.h"

class CPU6502_ASMFixture : public CPU6502_ASMTestFixture {};

TEST_F(CPU6502_ASMFixture, CRC32_ComputeTest) {
    // given:
    SetExecutable("../tools/asm_tests/CRC32_test.bin", mem, 0x3000);

    for(auto i = 0x1000; i < 0x1100; i++)
        mem[i] = 0x02;

    // when:
    RunTest();

    // then:
    EXPECT_EQ(mem[0x06], 0x64);
    EXPECT_EQ(mem[0x07], 0x80);
    EXPECT_EQ(mem[0x08], 0xDE);
    EXPECT_EQ(mem[0x09], 0xD4);

    //https://crccalc.com/?crc=0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 &method=crc32&datatype=hex&outtype=0
}

TEST_F(CPU6502_ASMFixture, CRC16_ComputeTest) {
    // given:
    SetExecutable("../tools/asm_tests/CRC16_test.bin", mem, 0x3000);

    for(auto i = 0x1000; i < 0x1100; i++)
        mem[i] = 0x02;

    // when:
    RunTest();

    // then:
    EXPECT_EQ(mem[0x06], 0xA1);
    EXPECT_EQ(mem[0x07], 0xF1);

    // https://crccalc.com/?crc=0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 &method=crc16&datatype=hex&outtype=0
}

TEST_F(CPU6502_ASMFixture, CRC8_ComputeTest) {
    // given:
    SetExecutable("../tools/asm_tests/CRC8_test.bin", mem, 0x3000);

    for(auto i = 0x1000; i < 0x1100; i++)
        mem[i] = 0x02;

    // when:
    RunTest();

    // then:
    EXPECT_EQ(cpu.A, 0x24);

    // https://crccalc.com/?crc=0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 0x02 &method=crc8&datatype=hex&outtype=0
}

TEST_F(CPU6502_ASMFixture, MultiplicationBy10_ComputeTest) {
    // given:
    SetExecutable("../tools/asm_tests/MultiplicationBy10_test.bin", mem, 0x8000);

    cpu.A = 0x12;               // Given: 18

    // when:
    RunTest();

    // then:
    EXPECT_EQ(cpu.A, 0xB4);     // Result: 180
}
