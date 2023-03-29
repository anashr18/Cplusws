#include<iostream>

class PolyNode{
    public:
        int coff;
        int expo;
        PolyNode *next;
        PolyNode(int , int, PolyNode*);
        
};
PolyNode::PolyNode(int coff, int expo, PolyNode *next=NULL)
{
    this->coff=coff;
    this->expo=expo;
    this->next=next;
}

class PolyChain
{
public:
    PolyNode *first, *last;
    int len;

public:
    PolyChain();
    ~PolyChain();
    void Insert(int, int, int);
    void Display();
    // PolyChain AddPoly(PolyChain*);
};

PolyChain::PolyChain()
{
    len=0;
    first=last=NULL;
}

PolyChain::~PolyChain()
{
    std::cout<< "Destructor"<< std::endl;
    PolyNode *p = first;
    while(p!=NULL){
        std::cout<< "Deleting " << p->coff <<"X"<<p->expo<< std::endl;
        p=p->next;
        delete first;
        first=p;
    }
}

void PolyChain::Insert(int pos, int coff, int expo)
{
    PolyNode *p = new PolyNode(coff, expo);
    // p->next = NULL;
    
    if(len==0){
        first=last=p;
    }
    else{
        if(pos==1){
            p->next = first;
            first = p;
        }
        else if(pos==len+1){
            last->next = p;
            last = p;
        }
        else{
            PolyNode *q = first;
            for(int i=1;i<=pos-2;i++)
                q=q->next;
            p->next = q->next;
            q->next = p;
        }
    }
    len++;
}

void PolyChain::Display()
{
    std::cout<< "Display" << std::endl;
    PolyNode *p = first;
    while(p!=NULL){
        std::cout<< p->coff <<"X"<<p->expo << "  ";
        p=p->next;
    }
    std::cout << "\n";
}

PolyChain AddPoly(PolyChain *a, PolyChain *b)
{   
    PolyChain result = PolyChain();
    PolyNode *p = a->first;
    PolyNode *q = b->first;
    int coff1, expo1, coff2, expo2 = 0;
    while(true){
        if(p==NULL && q==NULL)
            break;

        coff1 = (p==NULL)? 0: p->coff;
        expo1 = (p==NULL)? 0: p->expo;
        coff2 = (q==NULL)? 0: q->coff;
        expo2 = (q==NULL)? 0: q->expo;
       
        if(expo1 > expo2){
            result.Insert((result.len)+1,coff1, expo1);
            p=p->next;
        }
        else if(expo1 < expo2){
            result.Insert((result.len)+1,coff2, expo2);
            q=q->next;
        }
        else{
            result.Insert((result.len)+1,(coff1+coff2), expo1);
            p=p->next;
            q=q->next;
        }
    }
    return result;
}

int main(){
    PolyChain c, a;
    c.Insert(1,1,1);
    c.Insert(2,2,2);
    // c.Insert(3,3,3);
// asdnsaj
    c.Insert(3,4,4);
    a.Insert(1,1,1);
    a.Insert(2,2,2);
    a.Insert(3,3,3);
    // a.Insert(4,4,4);
    c.Display();
    a.Display();
    PolyChain d = AddPoly(&a, &c);
    d.Display();
    return 0;
}

// PolyChain AddPoly(PolyChain *a, PolyChain *b)
// {   
//     PolyChain result = PolyChain();
//     PolyNode *p = a->first;
//     PolyNode *q = b->first;
//     while(true){
//         while(p!=NULL && q!=NULL){
//         if(p->expo > q->expo){
//             result.Insert((result.len)+1,p->coff, p->expo);
//             p=p->next;
//         }
//         else if(p->expo < q->expo){
//             result.Insert((result.len)+1,q->coff, q->expo);
//             q=q->next;
//         }
//         else{
//             result.Insert((result.len)+1,(p->coff+q->coff), (p->expo+q->expo));
//             p=p->next;
//             q=q->next;
//         }
//     }
//         break;
//     }
    
//     return result;
// }