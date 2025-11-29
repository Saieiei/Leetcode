//the most easiest way is to use hashmaps
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for(string str: strs){
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(str);

        }
        for(auto& [sorted_str, groups]: mp){
            ans.push_back(groups);
        }
        return ans;
    }
};