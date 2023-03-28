#include<iostream>

template<class T>
class NodeCL{
    public:
        T data;
        NodeCL<T> *next;
};
template<class T>
class ChainCL{
    public:
        NodeCL<T> *first, *last;
        int len;
    public:
        ChainCL();
        ~ChainCL();
        void Insert(int, T);
        void Delete(int, T&);
        void Display();
};

template <class T>
ChainCL<T>::ChainCL(){
    first=NULL;
    last=NULL;
    len=0;
}

template <class T>
ChainCL<T>::~ChainCL()
{
    if(first!=NULL){
        std::cout<< "In destructor "<< std::endl;
        NodeCL<T> *p = first;
        while(p->next!=first)
            p=p->next;
        while(p!=first){
            p->next=first->next;
            std::cout<< "In destructor "<<first->data << std::endl;
            delete first;
            first=p->next;
        }
        if(p==first){
            std::cout << "Destructor First element "<< first->data << std::endl;
            delete first;
            first=NULL;
        }
    }
}

    

template <class T>
void ChainCL<T>::Insert(int pos, T Element)
{
    NodeCL<T> *temp = new NodeCL<T>;
    temp->data = Element;
    temp->next = temp;

    if(len==0){
        first=last=temp;
    }
    else{
        if(pos==1){
            temp->next=first;
            first=temp;
            last->next=first;
        }
        else if(pos==len+1){
            last->next = temp;
            last = temp;
            last->next = first;
        }
        else{
            NodeCL<T> *p = first;
            for(int i=1;i<=pos-2;i++)
                p=p->next;
            temp->next = p->next;
            p->next=temp;
        }
    }
    len++;
}

template <class T>
void ChainCL<T>::Delete(int pos, T &Element)
{
    NodeCL<T> *p, *q;
    if(len==0)
        std::cout<< "Circluar Linked list is empty "<< std::endl;
    else{
        if(pos==1){
            p=first->next;
            last->next=p;
            std::cout<< "deleting " << first->data << std::endl;
            delete first;
            first=p;
        }
        else if(pos==len){
            p=first;
            for(int i=1;i<len;i++)
                p=p->next;
            p->next=first;
            std::cout<< "deleting " << last->data << std::endl;
            delete last;
            last = p;
        }
        else{
            p=first;
            for(int i=1;i<=pos-2;i++)
                p=p->next;
            q=p->next;
            p->next = q->next;
            std::cout<< "deleting " << q->data << std::endl;
            delete q;
        }
    }
}

template <class T>
void ChainCL<T>::Display()
{
    NodeCL<T> *p=first;
    std::cout<< p->data <<"-->";
    p=p->next;
    while(p!=first){
        std::cout<< p->data <<"-->";
        p=p->next;
    }
    std::cout<< "\n";
}

int main(){
    ChainCL<int> a;
    a.Insert(1,10);
    a.Insert(2,20);
    a.Insert(3,30);
    a.Insert(4,40);
    a.Display();
    int x;
    a.Delete(2,x);
    a.Display();
    return 0;
}