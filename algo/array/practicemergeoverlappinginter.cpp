#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>*> mergeOverlappingIntervals(vector<vector<int>> intervals);

int main(){
    vector<vector<int>> array= {{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
    vector<vector<int>> output = mergeOverlappingIntervals(array);
    vector<vector<int>> testoutput;
    // for(auto arr:output){
        
    //     // for(auto elem:*arr){
    //     //     cout << elem <<",";  
    //     // }
    //     // cout << *arr[0];
    //     testoutput.push_back(*arr);
    //     // cout << ")";
    // }
    // for(vector<int> arr:testoutput){
    //     cout << "(";
    //     for(int elem:arr){
    //         cout << elem <<",";  
    //     }
    // }
    // for (int i = 0; i < v.size(); i++) {
    //     vector<int> *test = v[i];
    //     cout << *(test[0]) << " ";
    // }
 
    cout << endl;
    return 0;
}

vector<vector<int>*> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    // Write your code here.
    vector<vector<int>*> mergedinterval;
    vector<int> *currInterval = &intervals[0];
    mergedinterval.push_back(currInterval);
    for(vector<int> &nextInterval:intervals){
        int nextstart = nextInterval[0];
        int nextend = nextInterval[1];
        int currstart = currInterval->at(0);
        int currend = currInterval->at(1);
        if(currend>=nextstart){
            currInterval->at(1) = max(currend, nextend);
        } 
        else{
            currInterval = &nextInterval;
            mergedinterval.push_back(currInterval);
        }
       
    }
    return mergedinterval;
}