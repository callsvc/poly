#include <uma/unified.h>

namespace poly::uma {
    Unified::Unified() {
        devMemory.allocateBanks();
    }
    void reset() {
    }
}