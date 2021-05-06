//pybind11_wrapper.cpp
#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>

#include "fourier.hpp"

PYBIND11_MODULE(fourier, m)
{
    m.def("fft", &fft, "A function that caclulates fourier transform");
    m.def("ft", &ft, "A function that caclulates fast fourier transform");
}