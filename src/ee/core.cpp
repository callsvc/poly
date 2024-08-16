#include <ee/core.h>

namespace poly::ee {
    void Core::reset() {
        // Putting the PC directly onto the stack
        pc = 0xbfc00000;
    }
}

