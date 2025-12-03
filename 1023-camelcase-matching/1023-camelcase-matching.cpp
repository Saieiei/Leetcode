class Solution {
public:
    bool check(string q, string p) {
        int i = 0, j = 0;
        
        while (i < q.size()) {
            if (j < p.size() && q[i] == p[j]) {
                i++;
                j++;
            } else {
                if (isupper(q[i])) return false;
                i++;
            }
        }
        
        return j == p.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto q : queries) {
            ans.push_back(check(q, pattern));
        }
        return ans;
    }
};