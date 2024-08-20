cmake_minimum_required(VERSION 3.21)

target_sources(poly PRIVATE
    ee/core.cpp
    ee/core.h
    vm/system.cpp
    vm/system.h
    uma/memory.cpp
    uma/memory.h
    uma/unified.cpp
    uma/unified.h
    sys/bios.cpp
    sys/bios.h
    unit/pc.h
    poly.cpp
    types.h
)