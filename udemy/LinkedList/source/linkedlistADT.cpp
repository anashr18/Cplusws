#include<iostream>

template<class T>
class Node
{
    public:
        T data;
        Node<T> *link;
};
template<class T>
class Chain
{
    private:
        Node<T> *first, *last;
        int len;
    public:
        Chain();
        ~Chain();
        void Insert(int,T);
        void Display();
        void Delete(int, T&);
        bool FindLL(int, T&);
        int Search(T);
        bool isEmpty();
        void Merge(Chain<T>*, Chain<T>*);
        void Reverse();
};

template <class T>
Chain<T>::Chain()
{
    first=last=NULL;
    len=0;
}

template <class T>
Chain<T>::~Chain()
{
    std::cout << "Calling destructor" << std::endl;
    Node<T> *p=first;
    while(p){
        first=first->link;
        std::cout<< p->data <<" deleted";
        delete p;
        p=first;
    }
}

template <class T>
void Chain<T>::Insert(int pos, T element)
{
    // check len 
    // insert at first, last and in between them 
    Node<T> *p = new Node<T>;
    p->data = element;
    p->link = NULL;
    if(len==0){
        first = last = p;
    }
    else{
        if(pos==1){
            p->link = first;
            first = p;            
    }
        else if(pos==len+1){
            last->link = p;
            last = p;            
    }
        else{
            Node<T> *q = first;
            for(int i=1;i<=pos-2;i++)
                q=q->link;
            p->link = q->link;
            q->link = p;
    }
    }
    len++;
}

template <class T>
void Chain<T>::Display()
{
    Node<T> *temp=first;
    while(temp!=NULL)
        {
                std::cout<<temp->data<<"->";
                temp=temp->link;
        }
    std::cout<<"\n";
}

template <class T>
void Chain<T>::Delete(int pos, T &Element)
{
    Node<T> *p,*q;
    p=q=first;

    if(len==0){
        std::cout<<"Linked list is empty" <<std::endl;
        return;
    }
    else if(pos==1){
        // deleting the first node in LL
        first=first->link;
        // delete p;
        // ref to first Node in p
    }
    else if(pos==len){
        // deleting the last 
        for(int i=1;i<=len-2;i++)
            q=q->link;
        // ref to last Node in p
        p=q->link;
        q->link=NULL;
        last = q;
        // delete p;
    }
    else{
        for(int i=1;i<=pos-2;i++)
            q=q->link;
        p=q->link;
        q->link = p->link;
    }
    Element = p->data;
    delete p;
    len--;
}

template <class T>
bool Chain<T>::FindLL(int pos, T &Element)
{   
    if(pos<1 || pos>len){
        std::cout<< "invalid postion" << std::endl;
        return false;
    }
    Node<T> *p = first;
    for(int i=1;i<=pos-1;i++)
        p=p->link;
    Element = p->data;
    return true;
}

template <class T>
int Chain<T>::Search(T Element)
{   
    Node<T> *p = first;
    for(int i=1;i<=len;i++){
        if(Element==p->data)
            return i;
        p=p->link;
    }
    return -1;
}

template <class T>
bool Chain<T>::isEmpty()
{   
    return first==NULL;
}

template <class T>
void Chain<T>::Merge(Chain<T> *a, Chain<T> *b)
{
    Node<T> *f, *s, *p;
    f = a->first;
    s = b->first;
// establish first of merged chain C
    if(f->data < s->data){
            first = p= f;
            f=f->link;
        }
    else{
            first = p = s;
            s=s->link;
        }
    // p=first;
    first->link = NULL;

    while(f && s){
        if(f->data < s->data){
            p->link = f;
            p=f;
            f=f->link;
        }
        else{
            p->link = s;
            p=s;
            s=s->link;
        }
        p->link = NULL;
    }
}

template <class T>
void Chain<T>::Reverse()
{
    Node<T> *p, *q, *r;
    q=r=NULL;
    p = first;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->link;
        q->link=r;
    }
    first=q;
}

int main(){
    Chain<int> a, b, C;
    a.Insert(1,40);
    a.Insert(1,25);
    a.Insert(1,10);
    a.Display();
    a.Reverse();
    a.Display();
    b.Insert(1,35);
    b.Insert(1,30);
    b.Insert(1,20);
    b.Insert(1,5);
    b.Display();
    b.Reverse();
    b.Display();
    // C.Merge(&a, &b);
    // C.Display();
    // C.Reverse();
    // C.Display();
    // std::cout << "calling delete" <<std::endl;
    // int x;
    // C.Delete(1,x);
    // std::cout<< "deleted element is " << x << std::endl;
    // C.Display();
    // C.FindLL(3,x);
    // std::cout<< "Found element is " << x << std::endl;
    // x=C.Search(80);
    // if(x!=-1)
    //     std::cout<< "Element found at position " << x << std::endl;
    // x=C.Search(10);
    // if(x!=-1)
    //     std::cout<< "Element found at position " << x << std::endl;
    return 0;
}