#include<iostream>


int main(){
    // pointer to a pointer array
    int **a;
    a = new int*[3]; 
    for (int i=0;i<3;++i){
        a[i] = new int[5];
    }
    // deallocation
    for(int i=0;i<3;++i)
        delete [] a[i];
    delete [] a;

    // pointer array
    int *b[3];
    for(int i=0;i<3;++i)
        b[i] = new int[5];
    // deallocation
    for(int i=0;i<3;++i)
        delete[] b[i];

    return 0;
}

