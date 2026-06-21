class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //bijection mapping - space optimized
        //last seen index approach
        //N, U
        //bc
        if(s.length() != t.length()){
            return false;
        }
        //create 2 vectors, unicode
        vector<int> Svec(256, 0);
        vector<int> Tvec(256, 0);
        //if that letter is present in the map, 
        //then check if its mapped correctly or not
        for(int i=0; i<s.length(); i++){
            char Sch = s[i];
            char Tch = t[i];
            //if th evlaues r not same, then it doesnt follow the pattern
            if(Svec[Sch] != Tvec[Tch]){
                return false;
            }
            //record the last visited index
            //we do + 1 because we diff it from innitial 0
            Svec[Sch] = i + 1;
            Tvec[Tch] = i + 1;
        }
        return true;
    }
};