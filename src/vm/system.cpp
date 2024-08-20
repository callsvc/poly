#include <mutex>

#include <vm/system.h>
#include <uma/unified.h>
namespace poly::vm {
    System::System() {
        uma::devMemory.allocateBanks();
    }

    void System::produceFrames(const u32 countFrames) {
        std::scoped_lock lock{super};
        draw += countFrames;
    }
    void System::reset() {
        uma::reset();
        cpu.reset();
    }

    void System::tick() {
        if (!draw)
            return;
        if (draw) {
            std::scoped_lock lock{super};
            draw--;
        }
        cpu.tick(32);
    }
}
