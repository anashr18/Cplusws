#include<iostream>

template<class T>
class NodeDL{
    public:
        T data;
        NodeDL<T> *Lptr, *Rptr;
};
template<class T>
class ChainDL{
    private:
        int len;
        NodeDL<T> *first, *last;
    public:
        ChainDL();
        ~ChainDL();
        void Insert(int, T);
        void Display();
        void Delete(int, T&);
};

template <class T>
ChainDL<T>::ChainDL()
{
    len=0;
    first = NULL;
    last = NULL;
}

template <class T>
ChainDL<T>::~ChainDL()
{   
    std::cout << "Destructor called" << std::endl;
    NodeDL<T> *p = first;
    while(p!=NULL){
        std::cout << first->data << " deleted" << std::endl;
        delete first;
        p=p->Rptr;
        first=p;
    }
}

template <class T>
void ChainDL<T>::Insert(int pos, T Element)
{
    NodeDL<T> *temp = new NodeDL<T>;
    temp->data=Element;
    temp->Lptr = NULL;
    temp->Rptr = NULL;

    if(len==0){
        first = last = temp;
    }
    else{
        if(pos==1){
            temp->Rptr=first;
            first->Lptr=temp;
            first=temp;
        }
        else if(pos==len+1){
            last->Rptr = temp;
            temp->Lptr = last;
            last = temp;
        }
        else{
            NodeDL<T> *p = first;
            for(int i=1;i<pos-2;i++)
                p=p->Rptr;
            temp->Rptr = p->Rptr;
            temp->Lptr = p;
            p->Rptr->Lptr = temp;
            p->Rptr = temp;
        }
    }
    len++;
}

template <class T>
void ChainDL<T>::Display()
{
    NodeDL<T> *p = first;
    while(p!=NULL){
        std::cout << p->data << "--> ";
        p=p->Rptr;
    }
    std::cout << "\n";
}

template <class T>
void ChainDL<T>::Delete(int pos, T &)
{
    NodeDL<T> *p = first;
    NodeDL<T> *q;
    if(len==0)
        std::cout<<" Not initilazied" << std::endl;
    else{
        if(pos==1){
            q=first;
            first=q->Rptr;
            first->Lptr=NULL;
            std::cout<<"Deleting " << q->data << std::endl;
            delete q;
        }
        else if(pos==len){
            for(int i=1;i<=pos-2;i++)
                p=p->Rptr;
            q=p->Rptr;
            p->Rptr = NULL;
            last=p;
            std::cout<<"Deleting " << q->data << std::endl;
            delete q;
        }
        else{
            for(int i=1;i<=pos-2;i++)
                p=p->Rptr;
            q=p->Rptr;
            p->Rptr = q->Rptr;
            q->Rptr->Lptr = p;
            std::cout<<"Deleting " << q->data << std::endl;
            delete q;
        }
    }
    len--;
}

int main(){
    ChainDL<int> a;
    a.Insert(1,10);
    a.Insert(2,20);
    a.Insert(3,30);
    a.Insert(4,40);
    a.Display();
    int x ;
    a.Delete(1,x);
    a.Display();
    a.Delete(3,x);
    a.Display();
    return 0;
}