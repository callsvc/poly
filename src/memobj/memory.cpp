#include <cstring>
#include <sys/mman.h>

#include <memobj/memory.h>
namespace Poly::MemObj {
    void Memory::AllocateBanks() {
        constexpr auto VideoRam{4 * 1024 * 1024};
        constexpr auto BiosSlot{4 * 1024 * 1024};
        constexpr auto RequestSize{VideoRam + BiosSlot};

        const auto shared{mmap({}, RequestSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)};
        if (shared == MAP_FAILED)
            return;

        mapped = std::span{static_cast<u8*>(shared), RequestSize};
        gsMap = std::span{&mapped[0], VideoRam};
        biosMap = std::span{&mapped[VideoRam], BiosSlot};
    }

    void Memory::CleanUpMemory() const {
        std::memset(&biosMap[0], 0, biosMap.size());
    }
}
