#include<iostream>

class Myarray{
    private:
        int *array;
        int capacity;
        int size;
    public:
        Myarray(int arraycap=10);
        ~Myarray();
        bool isFull();
        bool isEmpty();
        int sizeofarray();
        friend std::istream& operator >>(std::istream& is, Myarray& a);
        friend std::ostream& operator <<(std::ostream& os, Myarray& a);
};

Myarray::Myarray(int arraycap): capacity{arraycap}
{
    std::cout << "calling the constructor" << std::endl;
    array = new int[capacity];
    size = 0;
}

Myarray::~Myarray()
{
    std::cout << "calling the destructor" << std::endl;
    delete [] array;
}

bool Myarray::isFull()
{
    if(capacity==size)
        return true;
    return false;
}

bool Myarray::isEmpty()
{   
    if(size==0)
        return true;
    return false;
}

int Myarray::sizeofarray()
{
    return size;
}

std::istream &operator>>(std::istream &is, Myarray &a)
{
    // TODO: insert return statement here
    std::cout << "enter element in array " << std::endl;
    is >> a.array[a.size++];
    return is;
}

std::ostream &operator<<(std::ostream &os, Myarray &a)
{
    // TODO: insert return statement here
    for(int i=0;i<a.size;++i)
        os << a.array[i] <<" ";
    return os; 
}


int main(){
    Myarray a(5);
    int num;
    std::cout << "how many elements you want to enter" << std::endl;
    std::cin >> num;
    for( int j=0;j<num;++j)
        std::cin >> a;
    std::cout << "entered elements are::" << a << std::endl;
    // std::cout 
    return 0;
}