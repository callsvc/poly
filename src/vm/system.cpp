#include <mutex>

#include <vm/system.h>
#include <uma/unified.h>

#include <sys/bios.h>
namespace poly::vm {
    void System::produceFrames(const u32 countFrames) {
        std::scoped_lock lock{super};
        draw += countFrames;
    }
    void System::initialize() {
        uma::devMemory.allocateBanks();
        bios = std::filesystem::current_path() / "bios";
        if (!is_directory(bios))
            create_directory(bios);
        std::filesystem::directory_iterator pick(bios);
        if (pick == std::filesystem::directory_iterator{}) {
            throw std::runtime_error("Could not find bios");
        }
        while (!pick->is_regular_file())
            ++pick;
        bios = *pick;

        psOs = sys::Bios{bios};
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
