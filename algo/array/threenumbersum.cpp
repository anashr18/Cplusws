#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum);

int main(){
    vector<int> input = {12, 3, 1, 2, -6, 5, -8, 6};
    int targetSum = 0;
    vector<vector<int>> output = threeNumberSum(input, targetSum);
    for (auto vec : output) {
        cout << "( ";
        for (auto elem : vec){
            cout << elem << ", ";
        }
        cout << ") ";
    }
    return 0;
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  sort(array.begin(), array.end());
  vector<vector<int>> triplets;
  for (int idx=0; idx<array.size()-2; idx++){
    int left = idx+1;
    int right = array.size()-1;
    while (left<right){
        int currentSum = array[idx]+array[left]+array[right];
        if (currentSum==targetSum){
            triplets.push_back({array[idx], array[left], array[right]});
            left++;
            right--;
        }
        else if(currentSum>targetSum){
            right--;
        }
        else if(currentSum<targetSum){
            left++;
        }
    }
  }
  
  return triplets;
}
