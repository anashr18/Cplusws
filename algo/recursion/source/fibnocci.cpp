#include<iostream>
#include<unordered_map>


int getNthFib(int n);
int helper(int n, std::unordered_map<int,int> &memo);

int main(){
    int n = 7;
    int output = getNthFib(n);
    std::cout << output << std::endl;
    return 0;
}

int getNthFib(int n) {
    std::unordered_map<int, int> memo({{1,0},{2,1}});
    int term = helper(n, memo);
    return term;
}

int helper(int n, std::unordered_map<int,int> &memo){
    if(memo.find(n)!=memo.end())
        return memo[n];
    else{
        memo[n] = helper(n-1,memo) + helper(n-2, memo);
        return memo[n];
    }
}

// int getNthFib(int n) {
//     if(n<1){
//         return -1;
//     }
//     if (n==1)
//         return 0;
//     if (n==2)
//         return 1;
//     else{
//         return getNthFib(n-1)+getNthFib(n-2);
//     }
// }