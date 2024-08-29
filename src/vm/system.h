#pragma once
#include <mutex>

#include <ee/core.h>
#include <sys/bios.h>
namespace poly::vm {
    class System {
    public:
        System() = default;

        void produceFrames(u32 countFrames = 1);
        void initialize();

        void reset();
        void tick();
        std::mutex super{};
        ee::Core cpu{};

        std::filesystem::path bios;
        sys::Bios psOs;
        u32 draw{};
    };
}