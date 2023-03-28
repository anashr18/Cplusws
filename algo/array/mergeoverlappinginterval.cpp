#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals);

int main(){
    vector<vector<int>> input = {{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
    vector<vector<int>> output = mergeOverlappingIntervals(input);
    // for (vector<int> *arr:output){
    //     cout << ".." ;
    //     for (int elem:*arr){
    //         cout << elem << ", ";
    //    }
    //    cout << ") ";
    // }
    for (vector<int> arr:output){
        // cout << "(" ;
        for (int elem:arr){
            // cout << elem << ", ";
       }
    //    cout << ") ";
    }
    cout << endl;
    return 0;
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
    vector<vector<int> *> merged;
    vector<int> *currInterval = &intervals[0];
    merged.push_back(currInterval);

    for(auto &nextInterval: intervals){
        int currInterval_end = currInterval->at(1);
        auto nextInterval_start = nextInterval[0];
        auto nextInterval_end = nextInterval[1];

        if (currInterval_end>=nextInterval_start){
            currInterval->at(1) = nextInterval_end;
        }
        else{
            currInterval = &nextInterval;
            merged.push_back(currInterval);
        }
    }
    // cout << merged.size() <<endl;
    vector<vector<int>> mergedCopy;
    for(vector<int> *interval: merged){
        // cout << interval.size() <<endl;
        vector<int> testarr = *interval;
        cout << testarr.size() << endl;
        cout << (*interval).size() << endl;
        for (int i = 0; i < (*interval).size(); i++) {
            // cout << *(interval + i) << " ";
            // int a = (*interval)[i];
            int a = interval->at(i);
            cout << a << ", ";
        }
        cout << endl;
        // mergedCopy.push_back(*interval);
    }
    return mergedCopy;
}
