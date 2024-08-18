#pragma once

#include <unit/pc.h>
namespace poly::ee {
    class Core {
    public:
        Core() = default;
        void reset();

        u32 fetchInstruction(u32 addr) const;

        void tick(u32 cycles);
    private:
        unit::Pc pc;
    };
}