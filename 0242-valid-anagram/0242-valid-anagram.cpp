class Solution {
public:
    bool isAnagram(string s, string t) {
        //hashmap method
        //N, N
        //bc
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int>mp;
        //populate the freq and depopulate the freq
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        //in the end we should all the freq as 0 only
        for(const pair<const char, const int>& it: mp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};