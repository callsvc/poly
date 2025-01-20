#include <fstream>

#include <sys/bios.h>
#include <memobj/memory.h>
namespace Poly::Sys {
    Bios::Bios(const std::filesystem::path& biosFile) {
        auto& slot{MemObj::devMemory.biosMap};

        if (!exists(biosFile)) {
            throw std::runtime_error("Bios file not found");
        }
        std::ifstream io{biosFile, std::ios::binary | std::ios::ate};

        if (const auto size{io.tellg()}; slot.size() != size) {
            throw std::runtime_error("Bios file size mismatch");
        }
        io.seekg(std::ios::beg);

        io.read(reinterpret_cast<char*>(&slot[0]), static_cast<std::streamsize>(slot.size()));
    }
}
