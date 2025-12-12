class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char ch) : data(ch), isTerminal(false) {
    for (int i = 0; i < 26; ++i) {
      children[i] = nullptr;
    }
  }
};

class Trie {
    //initialise the root TrieNode*
    TrieNode* root;

    //insert the dictionary word in trie
    void insertUtil(TrieNode* root, const string& word, int i) {
        //BC
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';
        if (!root->children[index]) {
            root->children[index] = new TrieNode(word[i]);
        }

        //R
        insertUtil(root->children[index], word, i + 1);
    }

    //check if the sentence-word can be replaced with the dict-word
        //if so at what index of the sentence-word
    bool searchUtil(TrieNode* root, const string& word, int& i) {
        //BC
        if (root->isTerminal) {
            return true;
        }
        if (i >= word.size()){
            return root->isTerminal;
        }

        int index = word[i] - 'a';
        i++;

        //R
        if (root->children[index]) {
            return searchUtil(root->children[index], word, i);
        }
        return false;
    }

public:
//create the root node
    Trie() {
        root = new TrieNode('\0');
    }
    
    //insert dictionary words in trie
    void insert(const string& word) {
        insertUtil(root, word, 0);
    }
    
    //check if the sentence-word can be replaced with the dict-word, 
        //if so at what index of the sentence-word
    int search(const string& word) {
        int i = 0; //index till where the word can be replaced 
        bool gotIt = searchUtil(root, word, i);
        return gotIt ? i : -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        string ans;
        
        //insert dictionary words in trie
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        //these r just 2 pointers to keep the track of the words in sentence
        int start = 0, end = 0;
        //u will stop when end reaches the end of the sentence
            //then internally it stops when u reach space or end of the sentence (/word)
        while (end <= sentence.size()) {
            if (end == sentence.size() || sentence[end] == ' ') {
                int len = end - start; //length of the word in the sentence
                string word = sentence.substr(start, len); //word
                int trieMatchIndex = trie.search(word); //this will give us the index
                //if the index is correct, then add that, else just add the word it self
                ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
                //after teh word has been modified, add space if not at the end
                if (end < sentence.size())
                    ans += " ";
                //move both 1 step ahead
                start = end + 1;
            }
            ++end;
        }
        
        return ans;
    }
};