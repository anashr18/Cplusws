#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string runLengthEncoding(string str);

int main(){
    string str = "AAAAAAAAAAAAABBCCCCDD";
    string output = runLengthEncoding(str);
    cout << output << endl;
    return 0;
}

string runLengthEncoding(string str) {
  string encoded = "";
  char first = str[0];
  int count = 1;
  for(int i =1; i < str.length(); i++){
    if(first!=str[i] || count==9){
        encoded+= to_string(count) + first;
        count=0;
        first = str[i];
    }
    ++count;
  }
  if(count!=0)
    encoded+= to_string(count) + first;
  return encoded;

}