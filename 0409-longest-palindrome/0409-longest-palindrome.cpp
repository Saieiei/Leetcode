class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        //calculating frequency of each characters in the string
        for(auto c: s)
        {
           freq[c]++;
        }
        int ans=0;
        bool isOdd=false;
        for(auto [ch, freq_value]: freq)
        {
            if(freq_value%2==0)
            {
                ans=ans+freq_value;
            }
            else
            {
                ans=ans+freq_value-1;
                isOdd=true;
            }
        }
        if(isOdd)
        {
            ans=ans+1;
        }

        return ans;
        
    }
};