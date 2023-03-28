#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string caesarCypherEncryptor(string str, int key);

int main(){
    string str = "zxwrset";
    int key = 5;
    string output = caesarCypherEncryptor(str, key);
    cout << output << endl;
    return 0;
}

string caesarCypherEncryptor(string str, int key) {
    string new_str = "";
    key = key%26;
    for(char c: str){
        char shift_char = int(c) + key;
        if((unsigned int)shift_char>int('z')){
            shift_char-=26;
        }
        new_str+=char(shift_char);
    }
    return new_str;
}