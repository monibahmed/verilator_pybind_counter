# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/usr/local/Cellar/verilator/5.018/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vcounter_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vcounter_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vcounter_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vcounter_COVERAGE 0)
# Timing mode?  0/1
set(Vcounter_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(Vcounter_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vcounter_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(Vcounter_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vcounter_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vcounter_CLASSES_SLOW "/Users/monibahmed/Projects/counter/build/CMakeFiles/Vcounter.dir/Vcounter.dir/Vcounter___024root__Slow.cpp" "/Users/monibahmed/Projects/counter/build/CMakeFiles/Vcounter.dir/Vcounter.dir/Vcounter___024root__DepSet_h5086c508__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(Vcounter_CLASSES_FAST "/Users/monibahmed/Projects/counter/build/CMakeFiles/Vcounter.dir/Vcounter.dir/Vcounter.cpp" "/Users/monibahmed/Projects/counter/build/CMakeFiles/Vcounter.dir/Vcounter.dir/Vcounter___024root__DepSet_h0dd033c2__0.cpp" "/Users/monibahmed/Projects/counter/build/CMakeFiles/Vcounter.dir/Vcounter.dir/Vcounter___024root__DepSet_h5086c508__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vcounter_SUPPORT_SLOW "/Users/monibahmed/Projects/counter/build/CMakeFiles/Vcounter.dir/Vcounter.dir/Vcounter__Syms.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(Vcounter_SUPPORT_FAST )
# All dependencies
set(Vcounter_DEPS "/usr/local/Cellar/verilator/5.018/share/verilator/include/verilated_std.sv" "/usr/local/bin/verilator_bin" "counter.v" )
# User .cpp files (from .cpp's on Verilator command line)
set(Vcounter_USER_CLASSES )
