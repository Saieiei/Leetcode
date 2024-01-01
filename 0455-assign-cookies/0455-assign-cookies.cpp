class Solution {
public:


    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int gSize = g.size();
        int sSize = s.size();
        int ans = 0;
        int gIndex = 0;

        for (int i = 0; i < sSize && gIndex < gSize; i++) {
            if (s[i] >= g[gIndex]) {
                ans++;
                gIndex++;
            }
        }

        return ans;
    }
};