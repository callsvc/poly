#include <cstring>
#include <memobj/unified.h>

#include <ee/core.h>
namespace Poly::EE {
    void Core::Reset() {
        std::memset(&gprs[0], 0, sizeof(gprs));
        // Putting the PC directly onto the stack
        pc = 0xbfc00000;
    }
    void Core::Exec() {
        const u32 fetchAddress{pc};
        pc++;
        MemObj::Read32(fetchAddress);
    }

    void Core::Tick(u32 cycles) {
        while (cycles--) {
            Exec();
        }
    }
}

