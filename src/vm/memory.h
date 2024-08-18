#pragma once
#include <span>

#include <types.h>
namespace poly::vm {
    class Memory {
    public:
        Memory() = default;

        std::span<u8> gsMap;
        std::span<u8> eeMap;
        std::span<u8> iopMap;
        std::span<u8> spuMap;
        std::span<u8> vuMap;
    };
}
