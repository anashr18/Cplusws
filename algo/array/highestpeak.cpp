#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestPeak(vector<int> array);

int main(){
    // vector<int> array = {1, 3, 2};
    vector<int> array = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    int output = longestPeak(array);
    cout << output << endl;
    return 0;
}

int longestPeak(vector<int> array) {
  // Write your code here.
    int peakLength = -1;
    for (int idx=0;idx<array.size();idx++){
        int leftIdx = idx-1;  
        int rightIdx = idx+1; 
        int currentPeakLength = 0; 
        while(leftIdx>=0){
            if (array[leftIdx]< array[leftIdx+1]){
                currentPeakLength++;
                leftIdx--;
            }
            else 
                break;
        }
        while(rightIdx<=array.size()){
        if (array[rightIdx]< array[rightIdx-1]){
                currentPeakLength++;
                rightIdx++;
            }
            else 
                break;
        }
        if (currentPeakLength>peakLength)
            peakLength = currentPeakLength;
    }
    return peakLength+1;
}