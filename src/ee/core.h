#pragma once

#include <array>
#include <unit/pc.h>
namespace Poly::EE {
    union Register {
        std::array<u32, 4> u4int;
        std::array<u8, 16> u16b;
    };

    union RegisterBlock {
        struct {
            Register
                r0, at, v0, v1, a0, a1, a2, a3,
                t0, t1, t2, t3, t4, t5, t6, t7,
                s0, s1, s2, s3, s4, s5, s6, s7,
                t8, t9, k0, k1, gp, sp, s8, ra;
        };
        std::array<Register, 32> regs;
        auto& operator [](auto index) {
            return regs[index];
        }
    };

    static_assert(sizeof(RegisterBlock) == 512);
    class Core {
    public:
        Core() = default;
        void Reset();

        void Exec();
        void Tick(u32 cycles);
    private:
        RegisterBlock gprs{};
        Unit::Pc pc;
    };
}