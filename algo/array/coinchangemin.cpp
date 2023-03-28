#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins);

int main(){
    vector<int> coins = {5, 7, 1, 1, 2, 3, 22};
    int output = nonConstructibleChange(coins);
    cout << output << endl;
    return 0;
}


int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
    sort(coins.begin(), coins.end());

    int currentChnageCreated = 0;
    for (int coin:coins){
      if ( coin > currentChnageCreated+1){
        return currentChnageCreated+1;
      }
      currentChnageCreated+=coin;
    }
    return currentChnageCreated+1;
}
