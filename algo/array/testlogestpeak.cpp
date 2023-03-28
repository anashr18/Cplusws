#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestPeak(vector<int> array);

int main(){
    vector<int> array= {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    int output = longestPeak(array);
    cout << output <<endl;
    return 0;
}

int longestPeak(vector<int> array) {
    // Write your code here.
    int currpeaklen = 0;
    int longestpeaklen = -1;
    int left =0;
    int right =0;
    for(int i=1;i<array.size()-1;i++){
        left = i;
        while (left>=0){
            if(array[left]>array[left-1])
                left--;
            else 
                break;
        }
        right = i+1;
        while (right<array.size()-1){
            if(array[right]>array[right+1])
                right++;
            else 
                break;
        }
        currpeaklen = right-left+1;
        if(currpeaklen>longestpeaklen)
            longestpeaklen=currpeaklen;
    }
    return longestpeaklen;
}
