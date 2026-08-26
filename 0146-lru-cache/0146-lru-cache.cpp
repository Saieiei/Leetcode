//this is a custom data structure
//we require maps and doubly LL to do all of this in O(1)
//map will be used to find the node in O(1) DLL will be used for LRU at O(1)
//it should also have head and tail, which r just dummy variables
//make sure to initialise these in the constructor and the capacity
//we will also need 2 fucntions, deleteNode() and inserAtBegining()
//when u use put, check if already there in the map
//if its already there in the map, then u duplicate this node, delete the old node
//put the duplicated node in the front and update the map with this new duplicate node
//if not then check for the size
//if size full then delete the last node and also remove from map
//if that also fine then insert it in the begining of the DLL and add it in the map as well
//get() is very simple
//check if the key is there in the map, if not return -1, if there then before returning its node value
//we need to put it in the front, so deleteNode() and inserAtBegining() and then only return the val
//no need to update map for this case
class LRUCache {
private:
    //create node
    class Node{
    public:
        int key, val;
        Node* next;
        Node* prev;
        //constructor
        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    //initialise head and tail
    Node* head;
    Node* tail;

    //create map
    unordered_map<int, Node*> mp;

    //useful functions
    void deleteNode(Node* nodeToDelete){
        Node* prevOfNodeToDelete = nodeToDelete->prev;
        Node* nextofNodeToDelete = nodeToDelete->next;
        prevOfNodeToDelete->next = nextofNodeToDelete;
        nextofNodeToDelete->prev = prevOfNodeToDelete;
    }
    void inserAtBegining(Node* nodeToInsert){
        Node* nextofNodeToInsert = head->next;
        head->next = nodeToInsert;
        nodeToInsert->prev = head;
        nextofNodeToInsert->prev = nodeToInsert;
        nodeToInsert->next = nextofNodeToInsert;
    }
    //capacity varibale 
    int capacity = 0;

    //from here make it public
    //constructor
public:
    LRUCache(int c) {
        //initialise capacity
        capacity = c;
        //initialse head and tail
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //check if its there in the map 1st
        if(mp.find(key) == mp.end()){
            //its not there, returm -1
            return -1;
        }
        //now its pakka there
        //get the node 1st, delete it and add it to the begining
        Node* nodetoGet = mp[key];
        deleteNode(nodetoGet);
        inserAtBegining(nodetoGet);
        return nodetoGet->val;
    }
    
    void put(int key, int value) {
        //check if its already there in the map 1st 
        if(mp.find(key) != mp.end()){
            //its already there in the map, so we just need to update the DLL
            //get the node update the node and put it in front
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            inserAtBegining(node);
            return;
        }
        //its not there in the node, so we have to check the size now
        if(mp.size() == capacity){
            //then we have to delete the LRU and insert the newNode in the begining
            Node* toDeleteNode = tail->prev;
            deleteNode(toDeleteNode);
            //also delete from map
            mp.erase(toDeleteNode->key);
            delete toDeleteNode;
        }
        //we have enough capacity, just insert
        Node* newNode = new Node(key, value);
        inserAtBegining(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */