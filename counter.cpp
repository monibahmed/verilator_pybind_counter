#include "Vcounter.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    Vcounter* top = new Vcounter;

    while (!Verilated::gotFinish()) {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        if (top->reset) {
            std::cout << "Resetting counter" << std::endl;
            top->reset = 0;
        }

        std::cout << "Counter: " << (int)top->out << std::endl;
    }

    delete top;
    return 0;
}