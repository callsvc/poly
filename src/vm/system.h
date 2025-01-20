#pragma once
#include <mutex>

#include <ee/core.h>
#include <sys/bios.h>
namespace Poly::Vm {
    class System {
    public:
        System() = default;

        void DoFrames(u32 countFrames = 1);
        void Initialize();

        void Reset();
        void Tick();
        std::mutex super{};
        EE::Core cpu{};

        std::filesystem::path bios;
        Sys::Bios psOs;
        u32 draw{};
    };
}