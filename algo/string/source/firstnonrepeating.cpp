#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int firstNonRepeatingCharacter(string string);

int main(){
    auto string = "abcdcaf";
    auto output = firstNonRepeatingCharacter(string);
    cout << output << endl;
    return 0;
}

int firstNonRepeatingCharacter(string string) {
    unordered_map<char, int> char_map;
    for(auto c: string){
        if(char_map.find(c)==char_map.end())
            char_map[c]=0;
        char_map[c]+=1;
    }
    int idx =0;
    for(auto c: string){
        if(char_map[c]==1)
            return idx;
        ++idx;
    }
    return -1;
}