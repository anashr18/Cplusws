#include<iostream>

int gcdhcf(int a , int b);
int helper(int a, int b, int num);

int main(){
    int a= 18;
    int b= 19;
    std::cout << gcdhcf(a , b) <<std::endl;
    return 0;
}

int gcdhcf(int a , int b){
    int num = std::min(a, b);
    // base case
    if(num == 1)
        return 1;
    return helper(a,b, num);
}

int helper(int a, int b, int num){
    float rem1 = a%num;
    float rem2 = b%num;
    if(rem1==0 && rem2==0)
        return num;
    return helper(a, b, num-1);
}