class Solution {
public:
    bool isAnagram(string s, string t) {
        //vector method - space optimized
        //N, N
        //bc
        if(s.length() != t.length()){
            return false;
        }
        //since it all lowercase we can use vectors of size 26
        vector<int>freq(26, 0);
        //populate the freq and depopulate the freq
        for(int i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        //in the end we should all the freq as 0 only
        for(const int& frequencyNo: freq){
            if(frequencyNo != 0){
                return false;
            }
        }
        return true;
    }
};