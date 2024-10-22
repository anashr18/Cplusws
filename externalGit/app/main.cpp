#include <Python.h>
#include <iostream>

#include "my_lib.h"
#include "config.hpp"

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

    return 0;
}