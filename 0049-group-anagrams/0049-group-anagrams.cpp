class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //same as valid anagram
        //fingerprinting + hashmap
        //N.k, N.k
        unordered_map<string, vector<string>> mp;
        //iterate through each word
        for(string s: strs){
            //get the key
            string key(26, 0);
            for(const char& ch: s){
                key[ch - 'a']++;
            }
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