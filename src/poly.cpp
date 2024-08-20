#include <iostream>
#include <thread>
#include <vm/system.h>
int main() {
    poly::vm::System emulator{};
    emulator.reset();

    std::thread thread([&] {
        // ReSharper disable once CppDFAEndlessLoop
        while (true) {
            emulator.tick();
        }
    });

    bool quit{};
    do {
        try {
            emulator.produceFrames();
        } catch (const std::exception& except) {
            std::cout << except.what() << std::endl;
            quit = true;
        }
    } while (!quit);

    return {};
}
