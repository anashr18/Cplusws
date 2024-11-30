#include <string>
#include <iostream>
class Node
{
private:
    int value;
    Node *next;

public:
    Node(const int &value = 0, Node *next = nullptr) : value(value), next(next) {}
    // returning a refrence to int ..it works here as value exists beyond the scope of the get function
    const int &getValue() const
    {
        return value;
    }
    // const int &value ..takes and l and r value refrence because of const
    void setValue(const int &value)
    {
        this->value = value;
    }
    Node *getNext() const
    {
        return next;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(const int &value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *curr = temp->getNext();
            delete temp;
            curr = temp;
        }
    }
    void printList() const
    {
        const Node *temp = head;
        while (temp)
        {
            std::cout << temp->getValue() << std::endl;
            temp = temp->getNext();
        }
    }
    void append(const int &value)
    {
        Node *temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        Node *newNode = new Node(value);
        temp->setNext(newNode);
    }
};

int main()
{
    LinkedList *ll = new LinkedList(4);
    ll->printList();
    ll->append(6);
    ll->append(8);
    ll->append(60);
    ll->printList();

    // delete ll;
    return 0;
}