#include<iostream>
using namespace std;

class Node 
{
    public:
        int data; // data of the node
        Node* next; // pointer to the next node
        
        Node() //default constructor
        {
            cout<<"Node created with default value"<<endl;
            data =0;
            this->next = NULL;
        }

        Node(int value) //parameterized constructor
        {
            cout<<"Node created with value: "<<value<<endl;
            this->data = value;
            this->next = NULL;
        }
};

int main()
{
    // Creating a node
    Node* zero = new Node();
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    //connecting a linked list
    zero->next = first;
    first->next = second;
    second->next = third;
}