#include <pybind11/pybind11.h>
#include "Vcounter.h"
#include "verilated.h"

namespace py = pybind11;

class PyVcounter {
public:
    PyVcounter() {
        top = new Vcounter;
    }
    ~PyVcounter() {
        delete top;
    }

    void eval() {
        top->eval();
    }

    void tick() {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
    }

    void reset(bool r) {
        top->reset = r;
    }

    int out() {
        return top->out;
    }

private:
    Vcounter* top;
};

PYBIND11_MODULE(Vcounter, m) {
    py::class_<PyVcounter>(m, "Vcounter")
        .def(py::init<>())
        .def("eval", &PyVcounter::eval)
        .def("tick", &PyVcounter::tick)
        .def("reset", &PyVcounter::reset)
        .def("out", &PyVcounter::out);
}