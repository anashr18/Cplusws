#include<iostream>
#include<vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence);

int main(){
    bool output = isValidSubsequence({5, 1, 22, 25, 6, -1, 8, 10}, {1, 6, 1, 10});
    cout << output << endl;
    return 0;
}


bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
    int arrlen = array.size();
    int seqlen = sequence.size();
    int arr = 0;
    int seq = 0;
    while (arr<arrlen && seq<seqlen){
        if (array[arr]==sequence[seq]){
             seq++;
    }
        arr++;
    }
    
  return bool(seq==seqlen);
}
 