#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

private:
    // DFS to backtrack from endWord to beginWord
    void dfs(string word, vector<string>& seq) {
        // Base condition: we successfully tracked back to the beginWord
        if (word == b) {
            // Because we backtracked from end to begin, the sequence is reversed.
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); // Put it back for further backtracking
            return;
        }
        
        int steps = mpp[word];
        
        // Try all possible 1-character transformations to find valid parents
        for (int i = 0; i < word.length(); i++) {
            char originalChar = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                // If this transformed word exists in our BFS map AND it is exactly
                // one step closer to the beginWord, it's a valid parent in the path.
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Remove the word to backtrack and try other paths
                }
            }
            word[i] = originalChar; // Restore the word for the next character check
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        
        q.push(beginWord);
        mpp[beginWord] = 1; // Map stores the word and the minimum steps to reach it
        st.erase(beginWord);
        
        // STEP 1: BFS to populate the shortest step-count for each word
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            // If we found the endWord, we don't need to map anything further than this depth
            if (word == endWord) break;
            
            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word); // Erase immediately to prevent cycles/longer paths
                        mpp[word] = steps + 1; // Record the step count
                    }
                }
                word[i] = originalChar;
            }
        }
        
        // STEP 2: DFS to build the paths backward if we reached the endWord
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
    }
};