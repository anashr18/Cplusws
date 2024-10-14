#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> multiply_by_factor(py::array_t<double> input, double factor) {
    py::buffer_info buf = input.request();
    auto result = py::array_t<double>(buf.size);
    py::buffer_info result_buf = result.request();

    double *ptr = static_cast<double *>(buf.ptr);
    double *result_ptr = static_cast<double *>(result_buf.ptr);

    for (size_t i = 0; i < static_cast<size_t>(buf.size); i++) {
        result_ptr[i] = ptr[i] * factor;
    }

    return result;
}

// std::vector<double> add_to_each(py::array_t<double> &input, double addend) {
//     std::vector<double> output;
//     output.reserve(input.size());
//     for (double item : input) {
//         output.push_back(item + addend);
//     }
//     return output;
// }

PYBIND11_MODULE(multiply_array, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("multiply_by_factor", &multiply_by_factor, "A function which multiplies all elements of a NumPy array by a double factor");
    // m.def("add_to_each", &add_to_each, "A function which addes all elements of a NumPy array by a double addend");
}
