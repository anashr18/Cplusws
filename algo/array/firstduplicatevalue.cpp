#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int firstDuplicateValue(vector<int> array);

int main(){
    vector<int> input = {2, 1, 5, 2, 3, 3, 4};
    int output = firstDuplicateValue(input);
    cout << output << endl;
    return 0;
}

int firstDuplicateValue(vector<int> array) { 
    unordered_map <int, bool> seen;
    for( int value:array){
        if(seen.find(value) != seen.end()){
            return value;
        }
        seen[value] = true;
    }
    return -1; 
}