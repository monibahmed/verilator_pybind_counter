cmake_minimum_required(VERSION 3.28)

project(counter)

set(CMAKE_CXX_STANDARD 14)

find_package(verilator REQUIRED)
find_package(pybind11 REQUIRED)

pybind11_add_module(Vcounter counter_pybind.cpp)

verilate(Vcounter
    SOURCES counter.v
    VERILATOR_ARGS -Wall
)

