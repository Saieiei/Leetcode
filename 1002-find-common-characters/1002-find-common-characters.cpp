class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map <char, int> freq;
        vector <string> ans; 
        //1st we will take the freq of the 1st string of words
        string s=words[0];
        for(auto c:s)
        {
            freq[c]++;
        }
        //now we shall create a new unordered_map tempfreq which will callculate the next sebsequent freq of the upcoming strings in the words vector
        for(int i=1;i<words.size();i++)
        {
            unordered_map <char, int> tempFreq;
            s=words[i];
            for(auto c:s)
            {
                tempFreq[c]++;
            }
            //now we will update our main unordered_map with the minimum number of characters as those characteres must be present in all the words
            for(auto& [ch, freq_char]: freq)
            {
                freq_char=min(freq_char, tempFreq[ch]);
            }
        }
        //creating the ans by pushing ch of the freq unordered_map into a vector
        for(auto [ch, freq_char]: freq)
        {
            while(freq_char--)
            {
            //since you're trying to push a character into a vector of strings.
            ans.push_back(string(1, ch));
            }                
            
        }
        return ans;

    }
};