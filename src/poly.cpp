#include <iostream>
#include <thread>
#include <vm/system.h>
int main() {
    Poly::Vm::System emulator{};
    emulator.Initialize();
    emulator.Reset();

    std::thread thread([&] {
        // ReSharper disable once CppDFAEndlessLoop
        while (true) {
            emulator.Tick();
        }
    });

    bool quit{};
    do {
        try {
            emulator.DoFrames();
        } catch (const std::exception& except) {
            std::cout << except.what() << std::endl;
            quit = true;
        }
    } while (!quit);

    return {};
}
