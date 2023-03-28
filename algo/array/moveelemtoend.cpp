#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> moveElementToEnd(vector<int> &array, int toMove);

int main(){
    vector<int> array = {2, 1, 2, 2, 2, 3, 4, 2};
    int toMove = 2;
    vector<int> output = moveElementToEnd(array, toMove);
    for (auto elem:output){
        cout << elem << ", ";
    }
    cout << endl;
    return 0;
}

vector<int> moveElementToEnd(vector<int> &array, int toMove) {
  // Write your code here.
    int leftIdx = 0;
    int rightIdx = array.size()-1;
    while (leftIdx< rightIdx){
        while (leftIdx < rightIdx && array[rightIdx]==toMove){
            rightIdx--;
        }
        if (array[leftIdx]==toMove){
                array[leftIdx] = array[rightIdx];
                array[rightIdx] = toMove;
                // swap(array[leftIdx], array[rightIdx]);
    }
        leftIdx++;
    }
  
    return array;
}