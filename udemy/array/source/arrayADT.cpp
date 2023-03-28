#include<iostream>

class IllegalParamValue{
    private:
        std::string message;
    public:
        IllegalParamValue(std::string msg): message(msg){};
        void outputMsg(){
            std::cout<< message << std::endl;
        }
};

template<class T>
class ArrayADT{
    private:
        T* array;
        int size;
        int capacity;
    public:
        ArrayADT(int arrCap);
        ~ArrayADT();
        void Insert(int pos, T elem);
        void Delete(int pos, T& elem);
        int Search(int a);
        void Display();
};

template <class T>
ArrayADT<T>::ArrayADT(int arrCap)
{
    if(arrCap < 1)
        throw IllegalParamValue("Capacity can not be negative");
    capacity = arrCap;
    size = 0;
    array = new T[capacity];
}

template <class T>
ArrayADT<T>::~ArrayADT()
{
    delete [] array;
    std::cout << "calling the destructor " << std::endl;
}

template <class T>
void ArrayADT<T>::Insert(int pos, T elem)
{
    if(pos<1 || pos>size+1)
        throw IllegalParamValue("invalid postion to insert element");

    for( int i=size-1; i>=pos-1;i--){
        array[i+1] = array[i];
    }
    array[pos-1] = elem;  
    size++;
}

template <class T>
void ArrayADT<T>::Delete(int pos, T& elem)
{
    if(pos<=0 || pos>size)
        std::cout << "invalid Position"
}

template <class T>
int ArrayADT<T>::Search(int a)
{

    return -1;
}

template<class T>
void ArrayADT<T>::Display()
{
    for( int i=0;i<size;i++)
        std::cout << array[i] << ", ";
    
}

int main()
{
    try{
        ArrayADT<int> a(10);
        a.Insert(1,100);
        a.Insert(1,200);
        a.Insert(1,300);
        int x;

        a.Display();
    }
    catch(IllegalParamValue e){
        e.outputMsg();
    }
    return 0;
}


