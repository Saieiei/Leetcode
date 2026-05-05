//not like toposorting, alien dictionary
//have to consider each word, each letter
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        //bc, already mentioned
        ///if(beginWord == endWord){
        ///    return 1;
        ///}
        //we have to keep the track of visited
        unordered_map<string, bool> isVisited;
        for(int i = 0; i < n; i++) {
            isVisited[wordList[i]] = false; 
        }

        int number = 1;
        //now lets start the bfs
        queue<pair<string, int>>q;
        q.push({beginWord, number});
        //mark it as visited
        isVisited[beginWord] = true;

        //start
        while(!q.empty()){
            //now we have to swap each letter with the alpha
            //create the new word
            //check if its there and push
            pair<string, int> frontData = q.front();
            q.pop();
            string frontWord = frontData.first;
            int frontNumber = frontData.second;
            //check if we have reached the end
            if(frontWord == endWord){
                return frontNumber;
            }
            //we have to create new words
            int wordLength = frontWord.size();
            for(int index = 0; index<wordLength; index++){
                //for each index, replace the char with alphabets
                for(char ch = 'a'; ch<='z'; ch++){
                    string newWord = frontWord;
                    newWord[index] = ch;
                    //find this new word
                    auto it = isVisited.find(newWord);
                    if(it != isVisited.end()){
                        //this word exits in the list
                        //make sure its no visited
                        if(isVisited[newWord] == false){
                            //its not visited
                            //mark it, push it in
                            int newNumber = frontNumber + 1;
                            q.push({newWord, newNumber});
                            isVisited[newWord] = true;
                        }
                    }
                }
            }
        }
        //didnt find the endWord
        return 0;
    }
};