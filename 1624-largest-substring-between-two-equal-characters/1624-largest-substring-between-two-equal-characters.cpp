class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // we will use 2 pointers approach
        int start=0;
        int end=s.size()-1;
        int ans=-1;
        while(start<=end)
        {
            if(s[start]==s[end])
            {
                ans=((end-start)-1>ans)?(end-start)-1:ans;
            }
            start++;
            end--;
        }
        return ans;
        
    }

};