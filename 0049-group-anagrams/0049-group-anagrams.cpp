class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //same as valid anagram
        //sorting + hashmap
        //N.klogK, N.K
        unordered_map<string, vector<string>> mp;
        //iterate through each word
        for(string s: strs){
            //get the key
            string key = s;
            sort(key.begin(), key.end());
            //map it
            mp[key].push_back(s);
        }
        //return answer in any order
        vector<vector<string>> result;
        //traverse through the map
        for(const pair<const string, const vector<string>>& it: mp){
            vector<string> values = it.second;
            result.push_back({values});
        }
        return result;

    }
};