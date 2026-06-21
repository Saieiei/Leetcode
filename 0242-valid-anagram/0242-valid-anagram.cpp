class Solution {
public:
    bool isAnagram(string s, string t) {
        //Brite force - sorting
        //NlogN, 
        //bc
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        //return (s==t);
        for(int i=0; i<s.length(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};