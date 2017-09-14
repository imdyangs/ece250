#include <iostream>
#include <string>
using namespace std;

class Node
{
    private:
        int value;
        Node *next;

    public:
        void setValue(int val);
        void setNext(Node* node);
        int getValue();
        Node* getNext();
        void print();
        Node();
};

Node::Node(void){
    this->next = 0;
}

void Node::setValue(int val)
{
    this->value = val;
    cout << "Set value of node as: " << val << endl;
}

void Node::setNext(Node* node)
{
    this->next = node;
}

int Node::getValue()
{
    return this->value;
}

Node* Node::getNext(){
    return this->next;
}

void Node::print()
{
    cout << "This node has value: " << this->value << endl;
}

class List
{
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        void insert(int val);
        void print();
        int getLength();
        int find(int val);
        List();
};

List::List()
{
    head = 0;
    tail = 0;
    length = 0;
}

// adds element to beginning of list
void List::insert(int val) {
    Node* newHead = new Node();
    newHead->setValue(val);
    if (length == 0)
    {
        head = newHead;
        tail = newHead;
        newHead->setNext(0);
        length++;
    }
    else
    {
        newHead->setNext(head);
        head = newHead;
        length++;
    }
    cout << "Inserted Value: " << val << " into the linked list." << endl;
}

int List::getLength()
{
    return this->length;
}

int List::find(int val){
    int position = 1;
    Node* traversalPtr = new Node();
    traversalPtr = head;
    try
    {
        while(traversalPtr != 0)
        {
            if (traversalPtr->getValue() == val)
            {
                return position;
            }
            position++;
            traversalPtr = traversalPtr->getNext();
        }
        throw "NotFound";
    }
    catch (string e)
    {
        cout << e << endl;
    }
}

void List::print(){
    Node* traversalPtr = new Node();
    traversalPtr = head;
    while(traversalPtr != 0)
    {
        traversalPtr->print();
        traversalPtr = traversalPtr->getNext();
    }
}

int main()
{
    List firstList;
    firstList.insert(2);
    firstList.insert(3);
    firstList.insert(4);
    
    int length = firstList.getLength();
    cout << "The length of this list is: " << length << endl << endl;

    firstList.print();
    int position = firstList.find(2);
    cout << position << endl;
}