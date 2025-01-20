#include <mutex>

#include <vm/system.h>
#include <memobj/unified.h>
#include <sys/bios.h>
namespace Poly::Vm {
    void System::DoFrames(const u32 countFrames) {
        std::scoped_lock lock{super};
        draw += countFrames;
    }

    void System::Initialize() {
        MemObj::devMemory.AllocateBanks();
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

        psOs = Sys::Bios{bios};
    }
    void System::Reset() {
        MemObj::Reset();
        cpu.Reset();
    }

    void System::Tick() {
        if (!draw)
            return;
        if (draw) {
            std::scoped_lock lock{super};
            draw--;
        }
        cpu.Tick(32);
    }
}
