#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv: " <<  *argv << std::endl;
    Vcounter* top = new Vcounter;
    
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        top->clk ^= 1;
        top->eval();
        m_trace->dump(sim_time);
        sim_time++;
        std::cout << "Counter: " << (int)top->out << std::endl;
    }

    m_trace->close();   
    delete top;
    return 0;
}