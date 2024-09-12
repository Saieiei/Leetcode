class Solution {
public:
    void checker(map<int, int>& alloChar, int& ans, string word)
    {
        int flag = 1; //innitally allowed
        for(char ch: word)
        {
            auto it = alloChar.find(ch);
            if(it != alloChar.end()) //the element is there
            {
                continue;
            }
            else flag = 0; //the element is not there
        }
        if(flag == 1)ans = ans+1;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans  = 0;

        //1st we will create a hash map,  that will store all the elemenets (allowed)
        map<int, int>alloChar;

        for(char ch: allowed)
        {
            alloChar[ch] = 1;
        }

        //now lets traverse through the words
        for(string word: words)
        {
            checker(alloChar, ans, word);
        }
        return ans;
    }   

};