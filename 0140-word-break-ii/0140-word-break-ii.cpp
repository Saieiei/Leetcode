//M1 Recursion
//not intuitive and hard to understand
//instead of using wordDict, we will create a unordered_map and use that
    //for quick look ups
//we will push all the words from the wordDict into the map
//recursion starts here with index 0
//start forming a word char by char (s) and see if its there in map
    //if not there then continue making the word
    //if its there then start forming the rightSideSentence via recursion (vector<string>)
//take every word fromed via rightSideSentence-append space and attach it to the word
//which was earlier formed 
class Solution {
public:

    vector<string> recursion(string& s, unordered_map<string, bool>& DictMP, int indx){
        //bc
        if(indx >= s.size()) return {""};
        vector<string> ans;

        //start making the word
        string word = "";
        for(int i = indx; i <= s.size() - 1; i++){
            word += s[i];
            if(DictMP.find(word) == DictMP.end()) continue;

            //found the word in the map
            vector<string> RightSideSentence = recursion(s, DictMP, i + 1); //dont do i++
            for(string RightSideWord : RightSideSentence){
                string SpaceWord = "";
                if(RightSideWord.size() > 0) 
                    SpaceWord = " " + RightSideWord;
                ans.push_back(word + SpaceWord); //dont put this iside if

                
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>DictMP;
        for(string word: wordDict) DictMP[word] = 1;
        int indx = 0;
        return recursion(s, DictMP, indx);
    }
};