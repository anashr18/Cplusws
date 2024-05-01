#include <iostream>
using namespace std;
int main() {
    int b1{};
    cout << b1 << '\n';
    char a1[4]{"hel"};
    cout << a1[0] << '\n';
    int *p1 = new int{};
    cout << *p1 << '\n';
    int *p2 = new int[3]{100,2,3};
    cout << *p2 << '\n';

    // narrowing conversions are not allowed 
    float f{};
    // int i{f}; this linegives an error as this can not be converted 
    return 0;
}
