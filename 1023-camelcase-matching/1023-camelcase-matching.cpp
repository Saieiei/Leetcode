class Solution {
public:

    bool matches(string& query, string& pattern) {
        int j = 0; // pattern index
        for (char c : query) {
            if (j < pattern.size() && c == pattern[j]) {
                // Use this query char to match current pattern char
                j++;
            } else if (isupper(c)) {
                // Uppercase that doesn't match pattern -> illegal
                return false;
            } else {
                // Lowercase that doesn't match -> allowed noise, skip
            }
        }
        // All pattern chars must have been matched
        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string query: queries){
            ans.push_back(matches(query, pattern));
        }
        return ans;
    }
};