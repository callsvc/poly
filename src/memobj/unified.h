#pragma once

#include <memobj/memory.h>
namespace Poly::MemObj {
    class Unified {
    public:
        Unified();

        template <typename T>
        static T Read(const u32 phAddr) {
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

    inline auto Read32(const u32 addr) {
        return Unified::Read<u32>(addr);
    }
    void Reset();
}