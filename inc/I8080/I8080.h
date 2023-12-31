#pragma once

#include "Macro.h"
#include "I8080_Status.h"
#include "CPU_Base.h"
#include "Memory.h"

#define PAGE_SIZE 0xFF
#define IsPageCrossed(src, dst) ((src ^ dst) >= PAGE_SIZE)

class I8080 final: public CPU_Base{
public:

    WORD PC;                // Program Counter
    WORD SP;                // Stack Pointer
    BYTE A;                 // Accumulator
    BiRegister B;
    BiRegister D;
    BiRegister H;
    I8080_Status Status;    // Status Register

    void Reset(Memory &memory, WORD resetVector = 0x0000) noexcept override;

    U32 Run(Memory &memory) override;

    FORCE_INLINE BYTE FetchByte(const Memory &memory) {
        const BYTE Data = memory[PC++];
        cycles++;
        return Data;
    }

    FORCE_INLINE WORD FetchWord(const Memory &memory) {
        const BYTE Lo = FetchByte(memory);
        const BYTE Hi = FetchByte(memory);
        return Lo | (Hi << 8);
    }

    FORCE_INLINE BYTE ReadByte(const Memory &memory, const WORD address) {
        const BYTE Data = memory[address];
        cycles++;
        return Data;
    }

    FORCE_INLINE WORD ReadWord(const Memory &memory, const WORD address) {
        const BYTE Lo = ReadByte(memory, address);
        const BYTE Hi = ReadByte(memory, address + 1);
        return Lo | (Hi << 8);
    }

    FORCE_INLINE void WriteByte(Memory &memory, const BYTE value, const WORD address) {
        memory[address] = value;
        cycles++;
    }

    FORCE_INLINE void WriteWord(Memory &memory, const WORD value, const WORD address) {
        memory[address] = value & 0xFF;
        cycles++;
        memory[address + 1] = (value >> 8);
        cycles++;
    }

    FORCE_INLINE void PushProgramCounterToStack(Memory &memory) {
        PushWordToStack(memory, PC - 1);
    }

    FORCE_INLINE WORD PopAddressFromStack(const Memory &memory) {
        return PopWordFromStack(memory) + 1;
    }

    FORCE_INLINE void PushStatusToStack(Memory &memory) {
        WriteByte(memory, Status, SP);
        SP--;
        cycles++;
    }

    FORCE_INLINE void PopStatusFromStack(const Memory &memory) {
        SP++;
        cycles++;
        Status = ReadByte(memory, SP);
        cycles++;
    }

    FORCE_INLINE void PushByteToStack(Memory &memory, const BYTE value) {
        WriteByte(memory, value, SP);
        SP--;
        cycles++;
    }

    FORCE_INLINE BYTE PopByteFromStack(const Memory &memory) {
        SP++;
        cycles++;
        const BYTE value = ReadByte(memory, SP);
        cycles++;
        return value;
    }

    FORCE_INLINE void PushWordToStack(Memory &memory, const WORD value) {
        WriteWord(memory, value, SP - 1);
        SP -= 2;
    }

    FORCE_INLINE WORD PopWordFromStack(const Memory &memory) {
        const WORD value = ReadWord(memory, SP + 1);
        cycles++;
        SP += 2;
        cycles++;
        return value;
    }

    FORCE_INLINE BYTE GetZeroPageValue(const Memory& memory) {
        const BYTE TargetAddress = FetchByte(memory);
        return ReadByte(memory, TargetAddress);
    }

    FORCE_INLINE WORD GetZeroPageAddress(const Memory& memory, const BYTE offsetAddress) {
        const BYTE TargetAddress = FetchByte(memory);
        cycles++;
        return TargetAddress + offsetAddress;
    }

    FORCE_INLINE BYTE GetZeroPageValue(const Memory& memory, const BYTE offsetAddress) {
        const BYTE TargetAddress = GetZeroPageAddress(memory, offsetAddress);
        return ReadByte(memory, TargetAddress);
    }

    FORCE_INLINE BYTE GetAbsValue(const Memory& memory) {
        const WORD TargetAddress = FetchWord(memory);
        return ReadByte(memory, TargetAddress);
    }

    FORCE_INLINE WORD GetAbsAddress(const Memory& memory, const BYTE offsetAddress) {
        const WORD AbsAddress = FetchWord(memory);
        const WORD TargetAddress = AbsAddress + offsetAddress;
        if (IsPageCrossed(TargetAddress, AbsAddress))
            cycles++;
        return TargetAddress;
    }

    FORCE_INLINE BYTE GetAbsValue(const Memory& memory, const BYTE offsetAddress) {
        const WORD TargetAddress = GetAbsAddress(memory, offsetAddress);
        return ReadByte(memory, TargetAddress);
    }
};
