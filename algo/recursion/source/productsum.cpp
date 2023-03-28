#include <any>
#include <iostream>
#include <vector>
#include <unordered_map>


int productSum(std::vector<std::any> array);
int helper(int n, std::unordered_map<int,int> &memo);

int main(){
    std::vector<std::any> test = {5, 2, std::vector<std::any>{7, -1}, 3,
                          std::vector<std::any>{6, std::vector<std::any>{-13, 8}, 4}};
    // int output = productSum(n);
    // std::cout << output << std::endl;
    // std::any v = 5;
    std::cout << __cplusplus << std::endl;
    return 0;
}

int productSum(vector<any> array) {
  // Write your code here.
  return -1;
}
