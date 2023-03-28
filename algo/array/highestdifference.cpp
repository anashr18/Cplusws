#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo);

int main(){
    vector<int> arrayOne = {-1, 5, 10, 20, 28, 3};
    vector<int> arrayTwo = {26, 134, 135, 15, 17};
    vector<int> output = smallestDifference(arrayOne, arrayTwo);
    for (auto elem:output){
        cout << elem << ", ";
    }
    cout << endl;
    return 0;
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int highest = INT16_MIN;
    int currentDiff = INT16_MAX;
    vector<int> higheststPair;
    int pointerOne = 0;
    int pointerTwo = 0;
    while (pointerOne< arrayOne.size() && pointerTwo< arrayTwo.size()){
        int numOne = arrayOne[pointerOne];
        int numTwo = arrayTwo[pointerTwo];
        if(numOne > numTwo){
            currentDiff = numOne-numTwo;
            pointerOne++;
        }
        else if(numOne < numTwo){
            currentDiff = numTwo-numOne;
            pointerTwo++;
        }
        // else{
        //     return {numOne, numTwo};
        // }
        if (highest<currentDiff){
            highest = currentDiff;
            higheststPair = {numOne, numTwo};
        }
    }
  return higheststPair;
}