#include <fstream>

#include <sys/bios.h>
#include <uma/memory.h>
namespace poly::sys {
    Bios::Bios(const std::filesystem::path& biosFile) {
        auto& slot{uma::devMemory.biosMap};
        if (!exists(biosFile)) {
            throw std::runtime_error("Bios file not found");
        }
        std::ifstream io{biosFile, std::ios::binary | std::ios::ate};
        const auto size{io.tellg()};
        if (slot.size() != size) {
            throw std::runtime_error("Bios file size mismatch");
        }
        io.seekg(std::ios::beg);

        io.read(reinterpret_cast<char*>(&slot[0]), slot.size());
    }
}
