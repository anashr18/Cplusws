#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool generateDocument(string characters, string document);

int main(){
    auto characters = "Bste!hetsi ogEAxpelrt x ";
    auto document = "AlgoExpert is the Best!";
    bool output = generateDocument(characters, document);
    cout << output << endl;
    return 0;
}

bool generateDocument(string characters, string document) {
    unordered_map<char, int> chars_map;
    for(auto c: characters){
        if (chars_map.find(c)==chars_map.end()){
            chars_map[c]=0;
        } 
        ++chars_map[c];
    }
    for(auto c: document){
        if (chars_map.find(c)==chars_map.end() || chars_map[c]==0){
            return false;
        } 
        --chars_map[c];
    }

    return true;
}