class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        //if u try to use find, it will not work, 
        //as find will only return the position of the word

        //in this case we have to count the freq of the sords
        //the best way to do it is by using unordered_maps

        //but in c++ it is had to extract each word from the sentence
        //for this case we will be using stringstream #include <sstream>

        stringstream ss (s1 + " " + s2);
        string word = "";
        unordered_map<string, int> wordFreq; //to find the freq of each word
        vector<string> ans;

        while(ss >> word)
        {   
            wordFreq[word]++;
        }

        for(auto& it: wordFreq)
        {
            if(it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};