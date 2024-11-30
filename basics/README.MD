## FROM THE PROJECT ROOT
```rm -rf build
mkdir build
cd build
cmake ..
cmake --build .

Returning by value is safe and efficient in modern C++ due to move semantics and RVO.
Returning by reference can be more efficient but requires ensuring the referenced object remains valid.
For temporary objects, prefer returning by value. Avoid returning references to temporaries as they lead to dangling references.
Consider using smart pointers when ownership semantics are necessary or when dealing with dynamically allocated objects.