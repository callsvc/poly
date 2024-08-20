#include <cstring>
#include <uma/unified.h>

#include <ee/core.h>
namespace poly::ee {
    void Core::reset() {
        std::memset(&gprs[0], 0, sizeof(gprs));
        // Putting the PC directly onto the stack
        pc = 0xbfc00000;
    }
    void Core::exec() {
        const u32 fetchAddress{pc};
        pc++;
        uma::readUma32(fetchAddress);
    }

    void Core::tick(u32 cycles) {
        while (cycles--) {
            exec();
        }
    }
}

