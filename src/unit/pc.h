#pragma once

#include <types.h>
namespace poly::unit {
    class Pc {
    public:
        Pc() = default;
        Pc(const u32 pc) : ip(pc) {}
        // ReSharper disable once CppNonExplicitConversionOperator
        operator u32() const { return ip; };

        auto operator ++(auto last) {
            (void)last;
            ip += 4;
        }

        u32 ip{};
    };
}