#include <iostream>
using namespace std;

int Add(int *p, int *q) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument
void AddRef(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void FactorialRef(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void SwapRef(int &a, int &b) ;            //Swap two numbers through reference arguments
int main(){
    int a{5};
    int b{6};
    int result{};
    int sum = Add(&a, &b);
    cout << sum << '\n';

    AddVal(&a, &b, &result);
    cout << result << '\n';
    
    cout <<"before"<< a << '\t' << b << '\n';
    Swap(&a , &b);
    cout << "after" << a << '\t' << b << '\n';
    Factorial(&a , &result);
    cout << "factorial" << a << '\t' << result << '\n';
    // int &res = result;
    AddRef(a, b, result);
    cout << "AddRef" << a << '\t' << b << '\t' << result << '\n';
    FactorialRef(a, result);
    cout << "FactRef" << a << '\t' << '\t' << result << '\n';
    // int &aref = a;
    // int &bref = b;
    SwapRef(a, b);
    cout << "SwapRef" << a << '\t'  << b << '\n';
    return 0;
};

void SwapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}; 

void AddRef(int a,int b, int &result) {
    result = a + b;
}; 

void FactorialRef(int a, int &result) {
    int fact{1};
    for(int i=2; i<=a; ++i){
        fact*=i;
    };
    result = fact;
};
void Factorial(int *a, int *result){
    int fact{1};
    for(int i=2; i<=*a; ++i){
        fact*=i;
    };
    *result = fact;
}; 
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
};

int Add(int *x, int *y) {
    int result = *x + *y;
    return result; 
};
void AddVal(int *a, int *b, int *result){
    *result = *a + *b;
};

