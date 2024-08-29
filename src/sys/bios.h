#pragma once

#include <filesystem>
namespace poly::sys {
    class Bios {
    public:
        Bios() = default;
        Bios(const std::filesystem::path& biosFile);

        bool slot{};
    };
}
