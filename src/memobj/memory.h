#pragma once
#include <span>

#include <types.h>
namespace Poly::MemObj {
    class Memory {
    public:
        Memory() = default;
        void AllocateBanks();
        void CleanUpMemory() const;

        std::span<u8> gsMap{};
        std::span<u8> biosMap{};
        std::span<u8> eeMap{};
        std::span<u8> iopMap{};
        std::span<u8> spuMap{};
        std::span<u8> vuMap{};

        std::span<u8> mapped{};
    };
    inline Memory devMemory;
}
