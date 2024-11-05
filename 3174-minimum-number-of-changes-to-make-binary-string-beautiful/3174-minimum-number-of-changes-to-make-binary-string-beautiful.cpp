class Solution {
public:
    int minChanges(string s) {
        //its easy only
        //we know that we have to use 2 pointers
        //there is nothitng like minimum nuber of chnages, becuase in the ened we will always check a group of 2 always
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n; i=i+2)
        {
            if(s[i]!=s[i+1]) ans++;
        }
        return ans;
    }
};