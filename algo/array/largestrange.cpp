#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array);

int main(){
    vector<int> nums = {8, 4, 2, 10, 3, 6, 7, 9, 1};
    // vector<int> nums = {1};
    // vector<int> nums = {1, 11, 3, 20, 15, 5, 2, 4, 10, 7, 12, 6};
    vector<int> output = largestRange(nums);
    for(int elem: output)
        cout << elem << endl;
    return 0;
}

vector<int> largestRange(vector<int> array) {
    // Write your code here.
    unordered_set<int> nums = {};
    // unordered_map<string, vector<int>> nums;
    int longestRange = 0;
    // vector<int> rangePair = {0,0};
    int minNum = INT16_MAX;
    int maxNum = INT16_MIN;
    for(int elem: array){
        minNum = min(minNum,elem);
        maxNum = max(maxNum,elem);
        nums.insert(elem);
    }
    int startRange = minNum;
    int endRange = maxNum;
    vector<int> rangePair = {startRange,endRange};
    int currNum = minNum+1;
    while(currNum <=maxNum+1){
        if(nums.find(currNum)==nums.end()){
            endRange = currNum-1;
            int range = endRange-startRange;
            if (longestRange<range){
                longestRange=range;
                rangePair ={startRange, endRange};
            }
            while (nums.find(currNum)==nums.end())
                currNum++;
            startRange = currNum;
        }
        currNum++;
    }
    return rangePair;
}
