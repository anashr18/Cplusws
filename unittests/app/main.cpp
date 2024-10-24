#include <Python.h>
#include <iostream>

#include "my_lib.h"
#include "config.hpp"

#include <cxxopts.hpp>
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

int main()
{
    print_hello_world();
    std::cout << project_version_major << std::endl;
    std::cout << project_version_minor << std::endl;
    std::cout << project_name << std::endl;
    std::cout << "sfdsjfjsdhfdsfsj" << std::endl;

    // Initialize the Python interpreter
    Py_Initialize();

    // Add the Python module's path to sys.path
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/ubuntu/Cplusws/externalGit/python_modules')");
    // /home/ubuntu/Cplusws/externalGit/python_modules

    // Import the hello module
    PyObject *pModule = PyImport_ImportModule("hello");
    if (!pModule)
    {
        PyErr_Print();
        std::cerr << "Failed to load Python module 'hello'" << std::endl;
        return -1;
    }

    // Get the say_hello function from the module
    PyObject *pFunc = PyObject_GetAttrString(pModule, "say_hello");
    if (!pFunc || !PyCallable_Check(pFunc))
    {
        PyErr_Print();
        std::cerr << "Function 'say_hello' not found or not callable" << std::endl;
        return -1;
    }

    // Call the say_hello function
    PyObject *pValue = PyObject_CallObject(pFunc, NULL);
    if (pValue == NULL)
    {
        PyErr_Print();
        std::cerr << "Failed to call Python function 'say_hello'" << std::endl;
        return -1;
    }

    // Get the returned value (expecting an integer)
    long result = PyLong_AsLong(pValue);
    std::cout << "Python function returned: " << result << std::endl;

    // Clean up
    Py_XDECREF(pFunc);
    Py_XDECREF(pModule);
    Py_Finalize();

    std::cout << project_name << '\n';
    std::cout << project_version << '\n';

    std::cout << "JSON:" << NLOHMANN_JSON_VERSION_MAJOR << "." << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "\n";

    std::cout << "FMT:" << FMT_VERSION << "\n";

    std::cout << "CXXOPTS:" << CXXOPTS__VERSION_MAJOR << "." << CXXOPTS__VERSION_MINOR << "." << CXXOPTS__VERSION_PATCH
              << "\n";

    std::cout << "SPDLOG:" << SPDLOG_VER_MAJOR << "." << SPDLOG_VER_MINOR << "." << SPDLOG_VER_PATCH << "\n";

    print_hello_world();

    return 0;
}