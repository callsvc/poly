#pragma once

#include <types.h>
namespace Poly::Unit {
    class Pc {
    public:
        Pc() = default;

        Pc(const u32 pc) : ip(pc) {} // NOLINT(*-explicit-constructor)
        explicit operator u32() const {
            return ip;
        }
        auto operator ++(auto last) {
            (void)last;
            ip += 4;
        }

        u32 ip{};
    };
}