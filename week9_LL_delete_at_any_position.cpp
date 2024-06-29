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

        ~Node(){
            cout<<"Node deleted with value: "<<this->data<<endl;
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
        temp = temp->next;
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

void insertAtBeg(Node* &head, int value) //always pass the node as refference
{
    //if there is no node in the linked list
    if(head==NULL)
    {
        //we will create a new node and assign it to the head
        Node* newNode = new Node(value);
        head = newNode;
    }
    else{
        //if there is a node in the linked list
        //we will create a new node
        Node* newNode = new Node(value);
        //we will connect the new node to the head
        newNode->next = head;
        //we will update the head to the new node
        head = newNode;
    }
}

void insertAtEnd(Node* &head, Node* &tail, int value)
{
    //if there is no node in the linked list
    if(head==NULL)
    {
        //we will create a new node and assign it to the head
        Node* temp = new Node(value);
        head = temp;
        tail = temp;
    }
    else{
        //if there is a node in the linked list
        //we will create a new node
        Node* temp = new Node(value);
        //we will connect the new node to the tail
        tail->next = temp;
        //we will update the tail to the new node
        tail = temp;
    }
}

void insertATPoition(Node* &head, Node* &tail, int value, int position)
{
    //if the position is 1, then we will insert at the beginning
    if(position <=1)
    {
        insertAtBeg(head, value);
    }
    //if the position is at the last, then we will insert at the end
    if(position >= lengthLL(head))
    {
        insertAtEnd(head, tail, value);
    }
    //if the position is in between
    else{
        Node* prev = NULL;
        Node* current = head;
        while(position != 1)
        {
            position --;
            prev = current;
            current = current->next;
        }
        //now since we r at the position, we will create a new node
        Node* newNode = new Node(value);
        //we will connect the new node to the current node
        //current node will be the next node of the new node
        newNode->next = current;
        //the previous node will be the previous node of the new node
        prev->next = newNode;
    }
}

void deleteAtPosition(Node* &head, Node* &tail, int position)
{
    //if there is no node AKA LL is empty
    if(head==NULL)
    {
        cout<<"Linked List is empty nothign can be deleted"<<endl;
        return;
    }

    //deleting if single element is present
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        cout<<"Linked List is empty now"<<endl;
        return;
    }

    //deleting head node AKA 1st node
    if(position == 1)
    {
        //1st we will isolate the 1st node
        Node* temp = head;
        //we will update the head to the next node
        head = head->next;
        //we will delete the 1st node
        delete temp; //deallocation of memory
        // Check if head becomes NULL after deletion
        if (head == NULL) {
        tail = NULL;
        }
    return;
    }

    //deleting the last node
    if(position>=lengthLL(head))
    {
        Node* prev = NULL;
        Node* curr = head;
        //we will traverse the LL till the last node
        while(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        //now since we r in the last node, we will delete the last node after isolating it
        prev->next = NULL;
        tail = prev;
        delete curr; //deallocation of memory
        return;
    }

    //deleting at any position
    else
    {
        Node* prev = NULL;
        Node* curr = head;
        //we will traverse the LL till the position
        while(position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        //now since we r at the position, we will delete the node after isolating it
        prev->next = curr->next;
        delete curr; //deallocation of memory
    }
}

int  main()
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
    Node* tail = fifth;


    //printing the linked list
    printLL(head);

    ////finding the length of the linked list
    //int length = lengthLL(head);
    //cout << "Length of the LinkedList is: " << length << endl;
//
    ////inserting a node at the beginging of the linked list
    //insertAtBeg(head, 5);
    //printLL(head);
//
    ////inserting a node at the beginging of the linked list
    //Node* tail = fifth;
    //insertAtEnd(head, tail, 60);
    //printLL(head);
//
    ////inserting at any position
    //insertATPoition(head, tail, 70, 3);
    //printLL(head);

    //deleting at any position
    deleteAtPosition(head, tail, 1);
    printLL(head);
}