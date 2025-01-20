#pragma once

#include <filesystem>
namespace Poly::Sys {
    class Bios {
    public:
        Bios() = default;

        explicit Bios(const std::filesystem::path& biosFile);

        bool slot{};
    };
}
