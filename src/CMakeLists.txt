cmake_minimum_required(VERSION 3.21)

target_sources(poly PRIVATE
    ee/core.cpp
    ee/core.h
    vm/system.cpp
    vm/system.h
    vm/memory.cpp
    vm/memory.h
    unit/pc.h
    poly.cpp
    types.h
)