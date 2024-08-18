#include <ee/core.h>

namespace poly::ee {
    void Core::reset() {
        // Putting the PC directly onto the stack
        pc = 0xbfc00000;
    }
    u32 Core::fetchInstruction([[maybe_unused]] u32 addr) const {
        if (!pc)
            return 1;
        return {};
    }
    void Core::tick(u32 cycles) {
        while (cycles--) {
            const auto instruction{fetchInstruction(pc)};
            (void)instruction;
            pc++;
        }
    }
}

