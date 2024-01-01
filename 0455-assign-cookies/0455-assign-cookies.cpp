class Solution {
public:


    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int sPointer=0;
        int gPointer=0;
        int ans=0;

        while(sPointer<s.size() && gPointer<g.size())
        {
            if(s[sPointer]>=g[gPointer])
            {
                sPointer++;
                gPointer++;
                ans++;
            }
           else
           {
              sPointer++; 
           }
        }
        return ans;
    }
};