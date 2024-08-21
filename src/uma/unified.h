#pragma once

#include <uma/memory.h>
namespace poly::uma {
    class Unified {
    public:
        Unified();

        template <typename T>
        static T read(const u32 phAddr) {
            auto kernelSeg{phAddr >= 0x80000000 && phAddr < 0x9fffffff};
            if (!kernelSeg)
                kernelSeg = phAddr >= 0xa0000000 && phAddr < 0xbfffffff;

            if (kernelSeg) {
                const auto effectivePhAddr{phAddr & 0x3fffff};
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