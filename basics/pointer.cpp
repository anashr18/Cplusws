#include <iostream>
using namespace std;

int main(){
    int a{32};
    int *p = &a;
    cout << p << '\n' << *p << '\n';
    *p = 189;
    cout << p << '\n' << *p << '\n';
    // derefrencing when * is on the right
    int y = *p; 
    cout << y << '\n';
    int *z = nullptr; 
    // nullpter can not be written to 
    int x{10};
    int &ref = x;
    cout << ref << '\n';
    // int *x = 7; 
    // cout << z <<'\n' << *z << '\n';
    return 0;
};