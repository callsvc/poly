#pragma once

#include <fstream>
namespace poly::sys {
    class Bios {
    public:
        Bios() = default;
        Bios(std::fstream& io);

        bool slot{};
    };
}
