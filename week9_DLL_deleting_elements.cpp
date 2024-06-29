#include<iostream>
using namespace std;

class Node{
    public:

        //we will add prev here because we are making a doubly linked list
        int data;
        Node* next;
        Node* prev;

        Node(){
            cout<<"Node created with default value"<<endl;
            data = 0;
            this->next = NULL;
            this->prev = NULL;  
        }    

        Node(int value)
        {
            cout<<"Node created with value: "<<value<<endl;
            this->data = value;
            this->next = NULL;
            this->prev = NULL;
        }

        ~Node(){
            cout<<"Node deleted with value: "<<this->data<<endl;
        }
};

void printDLL(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<endl;
}

int lengthDLL(Node* &head)
{
    int count =0;
    Node* temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtBeg(Node* &head, Node* &tail, int value)
{
    //if there is no node in the Doubly linked list
    if(head == NULL)
    {
        //we will create a new node and assign it to the head
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        //if there is a node in the Doubly linked list
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(Node* &head, Node* &tail, int value)
{
    //if there is no node in the doubly linked lit
    if(head  == NULL)
    {
        //we will create a new node and assign it to head
        Node* temp = new Node(value);
        head = temp;
        tail = temp;
    }
    else
    {
        //if there is already nodes in the doubly linked list
        Node* temp = new Node(value);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int value)
{
    //if the DLL is empty
    if(head == NULL)
    {
        Node* temp = new Node(value);
        head = temp;
        tail = temp;
        return;
    }

    //if the position is 1
    if(position == 1)
    {
        insertAtBeg(head, tail, value);
        return;
    }

    //if the position is at the end
    if(position > lengthDLL(head))
    {
        insertAtEnd(head, tail, value);
        return;
    }

    //if the position is in between
    else
    {
        Node* prev = NULL;
        Node* current = head;
        while(position != 1)
        {
            position--;
            prev = current;
            current = current->next;
        }
        Node* temp = new Node(value);
        prev->next = temp;
        temp->prev = prev;
        temp->next = current;
        current->prev = temp;
        return;
    }
}

void deleteAtPosition(Node* &head, Node* &tail, int position)
{
    //if the DLL is empty
    if(head == NULL)
    {
        cout<<"The DLL is empty nothign can be deleted"<<endl;
        return;
    }

    //if there is only 1 element in the DLL
    if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        cout<<"The DLL is empty now"<<endl;
        return;
    }

    //if the position is 1
    if(position == 1)
    {
        Node *temp = head;
        //we will update the head to the next node
        head = head->next;
        //we will update the previous of the new head to NULL
        head->prev = NULL;
        //we will delete the node
        delete temp;
        return;
    }

    //if the position is at the end
    if(position == lengthDLL(head))
    {
        Node* temp = tail;
        //we will update the tail to the previous node
        tail = tail->prev;
        //we will update the next of the new tail to NULL
        tail->next = NULL;
        //we will delete the node
        delete temp;
        return;
    }

    //if the position is in between
    else
    {
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        //now we are at the position to be deleted (curr)
        //we will connect the previous node to the next node
        prev->next = curr->next;
        //we will create a node which is nxt of current node
        Node* temp = curr->next;
        // we will connect the temp node to the previous node (prev)
        temp->prev = prev;
        //we will delete the current node
        delete curr;
        return;
    }
}

int main()
{
    //we will create nodes now (dynamic memory allocation)
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    //connecting the Doubly linked list
    Node* head = first;
    first->next = second;
    second->next = third;
    second->prev = first;
    third->next = fourth;
    third->prev = second;
    fourth->next = fifth;
    fourth->prev = third;
    fifth->prev = fourth;
    Node* tail = fifth;

    //printing the linked list
    printDLL(head);
    
    //finding the length of the linked list
    int length = lengthDLL(head);

    ////inserting a node at the beginging of the linked list
    //insertAtBeg(head, tail, 5);
    //printDLL(head);

    ////inserting a node at the end of the linked list
    //insertAtEnd(head, tail, 60);
    //printDLL(head);

    ////inserting at any position in the linked list
    //insertAtPosition(head, tail, 7, 15);
    //printDLL(head);

    //deleting at any position
    deleteAtPosition(head, tail, 6);
    printDLL(head);
}