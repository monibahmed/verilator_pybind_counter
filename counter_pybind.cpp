#include <pybind11/pybind11.h>
#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

namespace py = pybind11;

class PyVcounter {
public:
    PyVcounter() {
        //int argc = 1;
        //char* str[] = {"./Vcounter"};
        //char** ptr = str;
        //Verilated::commandArgs(argc, ptr);
        Verilated::traceEverOn(true);
        top = new Vcounter;
        m_trace = new VerilatedVcdC;
        top->trace(m_trace, 5);
        m_trace->open("waveform.vcd");
    }
    ~PyVcounter() {
        m_trace->close();
        delete top;
    }

    void eval() {
        tick();
        tick();
        std::cout << "Counter: " << (int)top->out << std::endl;
    }

    void reset(bool r) {
        top->reset = r;
    }

    int out() {
        return top->out;
    }

private:
    Vcounter* top;
    VerilatedVcdC *m_trace;
    vluint64_t sim_time = 0;

    void tick() {
        top->clk ^= 1;
        top->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

};

PYBIND11_MODULE(Vcounter, m) {
    py::class_<PyVcounter>(m, "Vcounter")
        .def(py::init<>())
        .def("eval", &PyVcounter::eval)
        .def("reset", &PyVcounter::reset)
        .def("out", &PyVcounter::out);
}