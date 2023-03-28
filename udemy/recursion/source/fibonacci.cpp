#include<iostream>
#include<unordered_map>

int fibonacci(int term);
int helper(int term, std::unordered_map<int,int> &um);

int main(){
    int term;
    std::cin >> term;
    std::cout << fibonacci(term) << std::endl;
    return 0;
}

int fibonacci(int term){
    // base case for number less than 1
    if(term<1)
        return -1;
    std::unordered_map<int, int> um({{1,0},{2,1}});
    return helper(term, um);
}

int helper(int term, std::unordered_map<int,int> &um){
    if(um.find(term)!=um.end())
        return um[term];
    um[term] = helper(term-1, um)+helper(term-2, um);
    return um[term];
}