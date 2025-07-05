class Solution {
public:
    //normalisation
    void normaliseString(string& s)
    {
        //1st create normalisation
        unordered_map<char, char> mp;
        char start = 'a';
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            if(mp.find(ch) == mp.end())
            {
                mp[ch] = start;
                start++;
            }
        }

        //2nd apply the normalisation
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            s[i] = mp[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //so basicall u have no otion to solve this untill u normalise these strings
        //so u normalise the list of strings and u also normalise the pattern
        //and if the normalised list of strings and the pattern are the same, then that string from the list of string is considered for output

        

        vector<string> ans;

        //take the pattern and normalise it
        normaliseString(pattern);

        //now normalise the list of strings and check if they are matching with the normalised pattern
        for(int i=0; i<words.size(); i++)
        {
            string checkPattern = words[i];
            normaliseString(checkPattern);
            if(checkPattern == pattern) ans.push_back(words[i]);
        }

        return ans;
    }
};