#include <memobj/unified.h>

namespace Poly::MemObj {
    Unified::Unified() {
        devMemory.AllocateBanks();
    }
    void Reset() {
    }
}