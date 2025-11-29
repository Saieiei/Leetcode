//create TrieNode* class
class TrieNode{
    public:
    char character;
    unordered_map<char, TrieNode*>children;
    bool isTerminal;
    TrieNode(char CharValue){
        character = CharValue;
        isTerminal = false;
    }
};

//insert using recursion
void insertRecursion(TrieNode* root, string word){
    //basecase
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    //take the 1st char of the word and check if the child exists in TrieNode
    char FirstChar = word[0];
    TrieNode* child;    //create the child TrieNode
    //check
    if(root->children.find(FirstChar) != root->children.end()) //found it, then link it
        child = root->children[FirstChar];
    else{ //didint find it, then create the child TrieNode* and link it
        child = new TrieNode(FirstChar);
        root->children[FirstChar] = child;
    }

    //the rest recursion will take care
    insertRecursion(child, word.substr(1));
}

bool SearchRecursion(TrieNode* root, string word){
    //basecase
    if(word.length() == 0)
        return root->isTerminal;

    //take the 1st char of the word and check if the child exists in TrieNode
    char FirstChar = word[0];
    TrieNode* child;  //create the child TrieNode
    //check
    if(root->children.find(FirstChar) != root->children.end()) //found it, then link it
        child = root->children[FirstChar];
    else //didint find it, then no such word
        return false;

    //the rest recursion will take care
    return SearchRecursion(child, word.substr(1));
}

bool startsWithRecursion(TrieNode* root, string prefix){
    //basecase
    if(prefix.length() == 0)
        return true;

    //take the 1st char of the word and check if the child exists in TrieNode
    char FirstChar = prefix[0];
    TrieNode* child;  //create the child TrieNode
    //check
    if(root->children.find(FirstChar) != root->children.end()) //found it, then link it
        child = root->children[FirstChar];
    else //didint find it, then no such word
        return false;

    //the rest recursion will take care
    return startsWithRecursion(child, prefix.substr(1));
}

class Trie {
public:
    //create the root node first to proceed
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }
    
    // we will do this using recursion
    void insert(string word) {
        insertRecursion(root, word);
    }
    
    // we will do this using recursion
    bool search(string word) {
        return SearchRecursion(root, word);
    }
    
    // we will do this using recursion
    bool startsWith(string prefix) {
        return startsWithRecursion(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */