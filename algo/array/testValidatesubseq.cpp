#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence);

int main(){
    // vector<int> array = {1, 3, 2};
    vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> sequence = {1, 6, -1, 10};
    int output = isValidSubsequence(array, sequence);
    cout << output << endl;
    return 0;
}

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
    int arrptr = 0;
    int seqptr = 0;
    while(arrptr < array.size() && seqptr < sequence.size()){
        if(array[arrptr]==sequence[seqptr]){
            seqptr++;
        }
        arrptr++;
    }
    return seqptr==sequence.size();
}