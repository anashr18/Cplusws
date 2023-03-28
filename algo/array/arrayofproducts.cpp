#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arrayOfProducts(vector<int> array);

int main(){
    vector<int> input = {5, 1, 4, 2};
    vector<int> output = arrayOfProducts(input);
    for (auto elem:output){
        cout << elem << ", ";
    }
    cout << endl;
    return 0;
}

vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
    vector<int> productArray(array.size(),1);
    int leftRunningProduct = 1;
    for(int idx = 0;idx<array.size();idx++){
        productArray[idx] = leftRunningProduct;
        leftRunningProduct*=array[idx];
    }
    int rightRunningProduct = 1;
    for(int idx = array.size()-1;idx>=0;idx--){
        productArray[idx] *= rightRunningProduct;
        rightRunningProduct*=array[idx];
    }

    return productArray;
}
vector<int> arrayOfProducts_1(vector<int> array) {
  // Write your code here.
  vector<int> productArray;
  for (int idx=0; idx<array.size();idx++){
    int leftIdx = idx-1;
    int rightIdx = idx+1;
    int currProduct = 1;
    while (leftIdx>=0){
        currProduct= currProduct*array[leftIdx];
        leftIdx--;
    }
    while (rightIdx<array.size()){
        currProduct= currProduct*array[rightIdx];
        rightIdx++;
    }
    productArray.push_back(currProduct);
  }
  return productArray;
}
