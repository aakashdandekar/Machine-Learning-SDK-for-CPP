#include<iostream>
#include<pybind11/pybind11.h>
#include<pybind11/stl.h>
using namespace std;
namespace py = pybind11;

#include "ClassicalMachineLearningModels/linear_regression.hpp"

PYBIND11_MODULE(ModelTraining, m) {
    py::class_<LinearRegression>(m, "LinearRegression")
        .def(py::init<double, long long, double>())
        .def("fit", &LinearRegression::fit)
        .def("predict", &LinearRegression::predict)
        .def("score", &LinearRegression::score);
}