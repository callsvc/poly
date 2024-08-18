#include <mutex>

#include <vm/system.h>
namespace poly::vm {
    void System::produceFrames(const u32 countFrames) {
        std::scoped_lock lock(super);
        genFrames += countFrames;
    }

    void System::reset() {
        cpu.reset();
    }

    void System::tick() {
        if (genFrames) {
            std::scoped_lock lock(super);
            genFrames--;
        } else {
            return;
        }

        cpu.tick(32);
    }
}
