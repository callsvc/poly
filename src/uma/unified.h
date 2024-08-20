#pragma once

#include <uma/memory.h>
namespace poly::uma {
    class Unified {
    public:
        Unified();

        template <typename T>
        static T read(u32 phAddr) {
            auto kernelSeg{phAddr >= 0x80000000 && phAddr < 0x9fffffff};
            if (!kernelSeg)
                kernelSeg = phAddr >= 0xa0000000 && phAddr < 0xbfffffff;

            if (kernelSeg) {
                phAddr &= 0x1fffffff;
                const auto effectivePhAddr{0x1fffffff - phAddr};
                return devMemory.biosMap[effectivePhAddr];
            }
            return {};
        }
    };
    inline Unified hostIo;

    inline auto readUma32(const u32 addr) {
        return hostIo.read<u32>(addr);
    }
    void reset();
}