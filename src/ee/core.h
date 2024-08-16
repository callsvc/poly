#pragma once
#include <types.h>
namespace poly::ee {
    class Core {
        Core();
    public:
        void write8();
        void write16();
        void write32();


        void reset();

    private:
        u32 pc;
    };
}