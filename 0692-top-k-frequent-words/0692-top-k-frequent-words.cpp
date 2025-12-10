#include <vector>
#include <string>
#include <queue>
#include <algorithm>

//this is for pq (MinHeap)
class comp {
public:
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
};

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int freq;

    TrieNode(char ch) : data(ch), isTerminal(false), freq(0) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i) {
        //basecase
        if (i >= word.size()) {
            root->isTerminal = true;
            root->freq++;
            return;
        }
        
        int index = word[i] - 'a';
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        //recursion
        insertUtil(root->children[index], word, i + 1);
    }

    void traverseUtil(TrieNode* root, string& s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k) {
        //BC
        if (!root) return;
        if (root->isTerminal) {
            if (pq.size() == k && root->freq > pq.top().first) {
                pq.pop();
                pq.push({root->freq, s});
            } else if (pq.size() < k) {
                pq.push({root->freq, s});
            }
        }
        //we need to travel on each kid that exists
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                s.push_back(i + 'a');
                //R
                traverseUtil(root->children[i], s, pq, k);
                //BT
                s.pop_back();
            }
        }
    }

public:
    Trie() : root(new TrieNode('\0')) {}

    void insert(string word) {
        insertUtil(root, word, 0);
    }

    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k) {
        string s;
        traverseUtil(root, s, pq, k);
    }
};

//reverse order 
bool mysort(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

//using tries
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        Trie trie;
        //insert the words into the trie (just like hashmaps)
        for (auto& word : words) {
            trie.insert(word);
        }

        //to insert every work in the pq
        trie.traverse(pq, k);

        vector<pair<int, string>> temp;
        while (!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }

        //the top elements will have less freq, so we have to reverse it
        sort(temp.begin(), temp.end(), mysort);

        vector<string> ans;
        for (auto& val : temp) {
            ans.push_back(val.second);
        }
        return ans;
    }
};