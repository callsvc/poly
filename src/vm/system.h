#pragma once
#include <mutex>

#include <ee/core.h>
namespace poly::vm {
    class System {
    public:
        System() = default;

        void produceFrames(u32 countFrames = 1);
        void initialize() const;

        void reset();
        void tick();
        std::mutex super{};
        ee::Core cpu{};

        u32 draw{};
    };
}