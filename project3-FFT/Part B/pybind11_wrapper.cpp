//pybind11_wrapper.cpp
#include <pybind11/pybind11.h>
#include<pybind11/complex.h>
#include <pybind11/stl.h>

#include "fourier.hpp"


PYBIND11_MODULE(fourier, m) {
    m.doc() = "pybind11 example plugin"; // Optional module docstring
    m.def("fft", &fft, "A function that multiplies two numbers");
    m.def("ft", &ft, "A function that multiplies two numbers");

}