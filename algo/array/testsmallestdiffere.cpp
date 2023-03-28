#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo);

int main(){
    vector<int> arrayOne ={-1, 5, 10, 20, 28, 3};
    vector<int> arrayTwo ={26, 134, 135, 15, 17};
    vector<int> output = smallestDifference(arrayOne, arrayTwo);

    for(int elem:output){
        cout << elem << ", ";
    }
    cout << endl;
    return 0;
}


vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    vector<int> smallestDifferencePair= {};
    int smallestdiff = INT16_MAX; 
    int currsmallestdiff = INT16_MAX; 
    int arroneptr = 0;
    int arrtwoptr = 0;
    while(arroneptr<arrayOne.size() && arrtwoptr<arrayTwo.size()){
        currsmallestdiff = abs(arrayOne[arroneptr]-arrayTwo[arrtwoptr]);
        if(arrayOne[arroneptr]==arrayTwo[arrtwoptr]){
            return {arrayOne[arroneptr], arrayTwo[arrtwoptr]};
        }
        if (currsmallestdiff< smallestdiff) {
        smallestdiff=currsmallestdiff;
        smallestDifferencePair = {arrayOne[arroneptr], arrayTwo[arrtwoptr]};
        // smallestDifferencePair.push_back(arrayOne[arroneptr]);
        // smallestDifferencePair.push_back(arrayTwo[arrtwoptr]);
        }
        if(arrayOne[arroneptr]<arrayTwo[arrtwoptr]){
            arroneptr++;
        }
        else if(arrayOne[arroneptr]>arrayTwo[arrtwoptr]){
            arrtwoptr++;
        }
     
    }
    return smallestDifferencePair;
}