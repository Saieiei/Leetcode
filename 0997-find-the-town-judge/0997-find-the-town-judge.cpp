class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1; // If there's only one person, they're automatically the judge.
        
        vector<int> trustCounts(n + 1, 0);
        
        for (const auto& t : trust) {
            trustCounts[t[0]]--; // Decrease for trusting others
            trustCounts[t[1]]++; // Increase for being trusted
        }
        
        for (int i = 1; i <= n; ++i) {
            if (trustCounts[i] == n - 1) {
                return i;
            }
        }
        return -1; // No judge found
    }
};