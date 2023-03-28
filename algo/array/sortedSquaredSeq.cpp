#include<iostream>
#include<vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array);

int main(){
    vector<int> output = sortedSquaredArray({-7, -2, 3, 5, 6, 8, 9});
    // cout << output;
     for (auto elem : output) {
        cout << elem << ", ";
    }
 
    cout << endl;
    return 0;
}


vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here. 
  vector<int> sortedArray(array.size(), 0);
  int smallerIdx = 0;
  int largerIdx = array.size()-1; 
  for (int idx=array.size()-1;idx>=0;idx--){
    int valueAtSmallerIdx = array[smallerIdx];
    int valueAtlargerIdx = array[largerIdx];

    if(abs(valueAtSmallerIdx)<abs(valueAtlargerIdx)){
        sortedArray[idx] = valueAtlargerIdx*valueAtlargerIdx;
        largerIdx--;
    } 
    else{
        sortedArray[idx] = valueAtSmallerIdx*valueAtSmallerIdx;
        smallerIdx++;
    } 
  }
  return sortedArray;
}
