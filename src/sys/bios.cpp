#include <sys/bios.h>
#include <uma/memory.h>
namespace poly::sys {
    Bios::Bios(std::fstream& io) {
        auto& slot{uma::devMemory.biosMap};
        io.seekg(std::ios::end);
        const auto size{io.tellg()};
        if (slot.size() != size) {

        }
        io.seekg(std::ios::beg);

        io.read(reinterpret_cast<char*>(&slot[0]), slot.size());
    }
}
