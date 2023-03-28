#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

bool zeroSumSubarray(vector<int> nums);

int main(){
    // vector<int> array = {1, 3, 2};
    vector<int> nums = {4, 2, -1, -1, 3};
    bool output = zeroSumSubarray(nums);
    cout << output << endl;
    return 0;
}

bool zeroSumSubarray(vector<int> nums) {
    // Write your code here.
    unordered_set<int> sums = {0};
    int currentSum = 0;
    for(int num:nums){
        currentSum+=num;
        if(sums.find(currentSum)!=sums.end())
            return true;
        sums.insert(currentSum);
    }
    return false;
}
