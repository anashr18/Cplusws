#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>>& array);

int main(){
    // vector<vector<int>> array = {
    //       {1, 2, 3, 4},
    //       {12, 13, 14, 5},
    //       {11, 16, 15, 6},
    //       {10, 9, 8, 7},
    //   };
    vector<vector<int>> array = {
            {1, 2, 3, 4},
            {10, 11, 12, 5},
            {9, 8, 7, 6}
      };
    // vector<vector<int>> array = {{1}};
    vector<int> output = spiralTraverse(array);
    for (auto elem:output){
        cout << elem << ", ";
    }
    cout << endl;
    return 0;
}

vector<int> spiralTraverse(vector<vector<int>> &array) {
  // Write your code here.
    if (array.size()==0)
        return {};
    vector<int> spiral = {};
    int startRow = 0;
    int endRow = array.size()-1;
    int startColumn = 0;
    int endColumn = array[0].size()-1;
    while(startRow<=endRow && startColumn<=endColumn){   
        for(int column=startColumn;column<=endColumn; column++){
            spiral.push_back(array[startRow][column]);
        }
        
        for(int row=startRow+1;row<=endRow; row++){
            spiral.push_back(array[row][endColumn]);
        }
        for(int column=endColumn-1;column>=startColumn; column--){
            if(startRow == endRow)
                break;
            spiral.push_back(array[endRow][column]);
        }
        
        for(int row=endRow-1;row>startRow; row--){
            if(startColumn == endColumn)
                break;
            spiral.push_back(array[row][startColumn]);
        }
        startRow++;
        endRow--;
        startColumn++;
        endColumn--;
    }
    return spiral;
}
