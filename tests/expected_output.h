#pragma once
// This file was autogenerated. Do not edit. //
#include "input.h"

void bind_input(nb::module_ &m)
{
    // Enums
    nb::enum_<TestEnum>(m, "TestEnum")
        .value("CAR", TestEnum::CAR)
        .value("TRUCK", TestEnum::TRUCK)
        .value("BIKE", TestEnum::BIKE);

    // Classes
    nb::class_<Test>(m, "Test", nb::intrusive_ptr<Test>([](Test* o, PyObject* po) noexcept { o->set_self_py(po); })
        .def(nb::init<>(), "Construct a new Test object")
        .def(nb::init<int &>(), "a"_a, "Construct a new Test object")
        .def("nontrivial_params", &Test::nontrivial_params, "a"_a, "b"_a = nullptr, "c"_a = std::vector<int>(), "Complex parameters\n\nArgs:\n    a: a\n    b: b\n    c: c")
        .def("overload", nb::overload_cast<double &>(&Test::overload), "a"_a, "An overloaded function\n\nArgs:\n    a: First param")
        .def("overload", nb::overload_cast<int>(&Test::overload), "b"_a, "An overloaded function\n\nArgs:\n    b: Alternate param")
        .def("__magic__", &Test::magic, "A magic method")
        .def("__magico__", nb::overload_cast<double &>(&Test::overload_magic), "a"_a, "An overloaded magic function\n\nArgs:\n    a: First param")
        .def("__magico__", nb::overload_cast<int>(&Test::overload_magic), "b"_a, "An overloaded magic function\n\nArgs:\n    b: Alternate param")
        .def_prop_ro_static("static_property", &Test::static_property, "Static property");

    nb::class_<Test2, Test>(m, "Test2")
        .def_prop_rw("name", &Test2::get_name, &Test2::set_name, "Get the name object\n\nReturns: The name")
        .def_prop_ro("prop", &Test2::get_prop, "Read-only property")
        .def("__iter__", &Test2::iter, "Iterate through this list\n\nReturns: iterator", nb::keep_alive<0, 1>());

    // Functions
    m.def("free", &free, "a"_a, "b"_a, "A free function\n\nArgs:\n    a: Hello\n    b: Bye\n\nReturns: Fye");

    m.def("free_return_simple", &free_return_simple, "A simple return type\n\nReturns: Simple return type");

};
