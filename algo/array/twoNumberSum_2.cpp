#include<iostream>
#include<vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum);

int main(){
    vector<int> output = twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 14);
    // cout << output;
     for (auto elem : output) {
        cout << elem << ", ";
    }
 
    cout << endl;
    return 0;
}

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  int leftIdx = 0;
  int rightIdx = array.size()-1;

  while (leftIdx < rightIdx){
    int currSum = array[leftIdx] + array[rightIdx];
    if (currSum == targetSum){
      return {array[leftIdx], array[rightIdx]};
    }
    else if (currSum > targetSum){
      rightIdx--;
    }
    else if (currSum < targetSum){
      leftIdx++;
    }
  }
  return {};
}
