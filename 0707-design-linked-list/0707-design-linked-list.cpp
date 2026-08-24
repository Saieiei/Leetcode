class MyLinkedList {
private:

    class Node {
    public:
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* dummy;
    int size;

public:

    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index) {

        if(index < 0 || index >= size) {
            return -1;
        }

        Node* curr = dummy->next;

        for(int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = dummy->next;
        dummy->next = newNode;

        size++;
    }

    void addAtTail(int val) {

        Node* curr = dummy;

        while(curr->next != nullptr) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);

        curr->next = newNode;

        size++;
    }

    void addAtIndex(int index, int val) {

        if(index < 0 || index > size) {
            return;
        }

        Node* prev = dummy;

        for(int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* newNode = new Node(val);

        newNode->next = prev->next;
        prev->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) {
            return;
        }

        Node* prev = dummy;

        for(int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* nodeToDelete = prev->next;

        prev->next = nodeToDelete->next;

        delete nodeToDelete;

        size--;
    }
};