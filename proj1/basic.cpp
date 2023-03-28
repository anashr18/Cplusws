#include<iostream>

using namespace std;

int main(){
    int a =10;
    int b =29;
    int* ptr {nullptr};
    ptr = &b; 
    cout << b << "  " << ptr << "  " << *ptr << endl;
    ptr = &a; 
    cout << a << "  " << ptr << "  " << *ptr << endl; 
    *ptr = 50;
    cout << b << "  " << ptr << "  " << *ptr << endl;
    cout << a << "  " << ptr << "  " << *ptr << endl;
    int* ptr1 {&b};
    cout << b << "  " << ptr1 << "  " << *ptr1 << endl;

    // int scores[] {10,20,30,40};
    // cout << scores << endl;
    // int* ptr = scores;
    // cout << ptr << "  "<< *ptr << endl; 
    // *ptr = 100;
    // cout << ptr << " testing "<< *ptr << endl; 
    // for (auto val:ptr)
    //     cout<< val;
    return 0;
}