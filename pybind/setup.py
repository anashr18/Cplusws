from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "multiply_array",
        ["multiply_array.cpp"],
    ),
]

setup(
    name="multiply_array",
    version="1.0",
    author="Your Name",
    description="A test module for C++ extensions",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
