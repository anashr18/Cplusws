#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2;
    vector<vector<int>> vec_2d;
    vec1.push_back(10);
    vec1.push_back(20);
    vec2.push_back(100);
    vec2.push_back(200);
    vec_2d.push_back(vec1);
    vec_2d.push_back(vec2);
    cout << vec_2d[0][0];
    cout << "hello";
    return 0;
}