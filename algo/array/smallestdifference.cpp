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
    int smallest = INT16_MAX;
    int currentDiff = INT16_MAX;
    vector<int> smallestPair;
    int pointerOne = 0;
    int pointerTwo = 0;
    while (pointerOne< arrayOne.size() && pointerTwo< arrayTwo.size()){
        int numOne = arrayOne[pointerOne];
        int numTwo = arrayTwo[pointerTwo];
        if(numOne > numTwo){
            currentDiff = numOne-numTwo;
            pointerTwo++;
        }
        else if(numOne < numTwo){
            currentDiff = numTwo-numOne;
            pointerOne++;
        }
        else{
            return {numOne, numTwo};
        }
        if (smallest>currentDiff){
            smallest = currentDiff;
            smallestPair = {numOne, numTwo};
        }
    }
  return smallestPair;
}