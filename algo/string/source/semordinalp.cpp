#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<string>> semordnilap(vector<string> words);

int main(){
    vector<string> input = {};
    // vector<vector<string>> expected = {{"desserts", "stressed"}};
    vector<vector<string>> actual = semordnilap(input);
    for(int i=0;i<actual.size();i++){
        vector<string> vec = actual[i];
            for(string str: vec)
                cout << str << endl;
        }
    return 0;
}

vector<vector<string>> semordnilap(vector<string> words) {
    vector<vector<string>> result;
    string first = "";
    string second = "";
    if(!words.empty()){
    int vec_size = words.size();
    for(int i=0;i<words.size()-1;i++){
        for(int j=i+1;j<words.size();j++){
            if(words[i].size()==words[j].size()){
                first = words[i];
                second = words[j];
                int leftIdx = 0;
                int rightIdx = words[i].size()-1;
                while(leftIdx<rightIdx){
                    if(first[leftIdx]!=second[rightIdx])
                        continue;
                    ++leftIdx;
                    --rightIdx;
                }
                result.push_back({first, second});
            }
        }
    }
    }
    return result;
}