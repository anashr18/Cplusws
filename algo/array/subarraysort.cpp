#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

vector<int> subarraySort(vector<int> array);
bool isOutOfOrder(int i, vector<int> array);

int main(){
    // vector<int> array = {1, 3, 2};
    vector<int> nums = {20, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    vector<int> output = subarraySort(nums);
    for(int elem: output)
        cout << elem << endl;
    return 0;
}

vector<int> subarraySort(vector<int> array) {
    // Write your code here.
    int minNum = INT16_MAX;
    int maxNum = INT16_MIN;
    for (int i=0;i<array.size();i++){
        if(isOutOfOrder(i, array)){
            minNum = min(minNum, array[i]);
            maxNum = max(maxNum, array[i]);
        }
    }
    int idx=0;
    while (minNum>=array[idx])
    {
        idx++;
    }
    int leftIdx=idx;

    idx=array.size()-1;
    while (maxNum<=array[idx])
    {
        idx--;
    }
    int rightIdx=idx;
    return {leftIdx, rightIdx};
}

bool isOutOfOrder(int i, vector<int> array){
    if(i==0)
        return array[i]>array[i+1];
    if(i==array.size()-1)
        return array[i]<array[i-1];
    return array[i]>array[i+1] || array[i]<array[i-1]; 
}