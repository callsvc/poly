cmake_minimum_required(VERSION 3.21)

target_sources(poly PRIVATE
    ee/core.cpp
    ee/core.h
    vm/system.cpp
    vm/system.h
    memobj/memory.cpp
    memobj/memory.h
    memobj/unified.cpp
    memobj/unified.h
    sys/bios.cpp
    sys/bios.h
    unit/pc.h
    poly.cpp
    types.h
)