//traversal
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dupWordList(wordList.begin(), wordList.end());
        int level = 1;
        queue<pair<string, int>>q;
        q.push({beginWord, level});
        dupWordList.erase(beginWord);

        //start
        while(!q.empty()){
            pair<string, int> frontData = q.front();
            q.pop();
            string word = frontData.first;
            int level = frontData.second;
            //check if this is the endword
            if(word == endWord){
                return level;
            }
            //create new words // explore the nbrs
            int wordSize = word.length();
            for(int index=0; index<wordSize; index++){
                //change the char in the index
                //alphabets
                for(char ch='a'; ch<='z'; ch++){
                    string newWord = word;
                    newWord[index] = ch;
                    if(dupWordList.count(newWord)){
                        //found it
                        //mark it as visited
                        int newLevel = level + 1;
                        q.push({newWord, newLevel});
                        dupWordList.erase(newWord);
                    }
                }
            }
        }
        //not possible 
        return 0;
    }
};