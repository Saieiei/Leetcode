class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        //its simple only
        //we will use hash to grp them together
        //then we will sort those grps and push it into vector<vector<string>>

        unordered_map<string, vector<string>> grouper;
        //group anagrams
        for(string str: strs)
        {
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());
            grouper[sort_str].push_back(str);
        }

        vector<vector<string>> ans;

        //we will sort the vector<string> and push into ans to return it
        for(auto& [key, group]: grouper)
        {
            //sort(group.begin(), group.end());
            ans.push_back(group);
        }

        //finally sort ur ans
        //sort(ans.begin(), ans.end());
        return ans;
    }
};