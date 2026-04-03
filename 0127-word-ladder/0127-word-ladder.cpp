//BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        //bc
        if(beginWord == endWord) return 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); //word, iteration

        while(!q.empty()){
            pair<string, int> frontNode = q.front();
            q.pop();
            string currWord = frontNode.first;
            int interation = frontNode.second;

            //check
            if(currWord == endWord) return interation;

            //create new word
            for(int index = 0; index<currWord.length(); index++){
                string originalWordSave = currWord;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    currWord[index] = ch; //curWord has been changed
                    string newWord = currWord;
                    if(st.find(newWord) != st.end()){ //found the word
                        q.push({newWord, interation + 1});
                        st.erase(newWord);
                    }
                }
                currWord = originalWordSave;
            }
        }
        //not possible
        return 0;

    }
};