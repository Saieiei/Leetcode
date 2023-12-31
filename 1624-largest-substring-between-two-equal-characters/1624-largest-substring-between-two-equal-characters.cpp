class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // we will use 2 pointers approach
        //int start=0; ->i
        //int end=s.size()-1; ->j
        int ans=-1;
        for(int i=0;i<s.size();i++)
        {
            for(int j=s.size()-1;j>i;j--)
            {
                if(s[i]==s[j])
                {
                    ans=((j-i)-1>ans)?(j-i)-1:ans;
                }
            }
        }
        return ans;
        
    }

};