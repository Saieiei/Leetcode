#include<iostream>
using namespace std;

class Node{
    public:

        int data;
        Node* next;

        Node(){
            cout<<"Node created with default value"<<endl;
            data = 0;
            this->next = NULL;
        }

        Node(int value){
            cout<<"Node created with value: "<<value<<endl;
            this->data = value;
            this->next = NULL;
        }
};

void printLL(Node* head)
{
    //always use a temp node to traverse the linked list, never use the address of the head node
    Node* temp = head;
    // temp is like a pointer that will traverse the linked lis, its like a index traversing the LL
    while(temp!= NULL)
    {
        // Print the data of the current node
        cout<<temp->data<<"->";
        // Move to the next node
        temp= temp->next;
    }
    cout << endl;
}

int lengthLL(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    //cerating nodes with values , dynamically
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    //connecting the linked list
    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    //printing the linked list
    printLL(head);

    //finding the length of the linked list
    int length = lengthLL(head);
    cout << "Length of the LinkedList is: " << length << endl;
}