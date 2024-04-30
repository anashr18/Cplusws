#include <iostream>
using namespace std;

int main(){
    char buff[100];
    cout << "what is your name?" << endl;
    cin.getline(buff, 100, '\n');
    // cin >> buff;
    cout << "Your name is"  << buff << '\n';
};