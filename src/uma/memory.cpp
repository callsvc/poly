#include <cstring>
#include <sys/mman.h>

#include <uma/memory.h>
namespace poly::uma {
    void Memory::allocateBanks() {
        constexpr auto videoRam{4 * 1024 * 1024};
        constexpr auto biosSlot{4 * 1024 * 1024};
        constexpr auto requestSize{videoRam + biosSlot};

        const auto shared{mmap({}, requestSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)};
        if (shared == MAP_FAILED)
            return;

        mapped = std::span{static_cast<u8*>(shared), requestSize};
        gsMap = std::span{&mapped[0], videoRam};
        biosMap = std::span{&mapped[videoRam], biosSlot};
    }

    void Memory::cleanUpMemory() {
        std::memset(&biosMap[0], 0, biosMap.size());
    }
}
