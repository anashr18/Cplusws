#include<iostream>
#include<vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum);

int main(){
    vector<int> output = twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 10);
    // cout << output;
     for (auto elem : output) {
        cout << elem << ", ";
    }
 
    cout << endl;
    return 0;
}

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  for(int i = 0; i < array.size()-1;i++){
    int firstNum = array[i];
    for(int j = i+1; j < array.size();j++){
        int secondNum = array[j];
        if (firstNum + secondNum==targetSum){
            return vector<int> {firstNum, secondNum};
        }
    }
  }
  return {};
}
