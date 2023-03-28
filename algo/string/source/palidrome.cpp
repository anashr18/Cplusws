#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string isPalindrome(string str);

int main(){
    string str = "abcdcba";
    string output = isPalindrome(str);
    cout << output << endl;
    return 0;
}

string isPalindrome(string str) {
  // Write your code here.
  int leftIdx = 0;
  int rightIdx = str.length()-1;
  while(leftIdx < rightIdx){
    if(str[leftIdx]!=str[rightIdx])
      return "False";
    ++leftIdx;
    --rightIdx;
  }
  return "True";
}