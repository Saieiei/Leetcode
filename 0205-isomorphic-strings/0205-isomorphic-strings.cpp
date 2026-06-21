class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //brute force bijection mapping
        //N, U
        //bc
        if(s.length() != t.length()){
            return false;
        }
        //create 2 hash maps
        unordered_map<char, char> StoT;
        unordered_map<char, char> TtoS;
        //if that letter is present in the map, 
        //then check if its mapped correctly or not
        for(int i=0; i<s.length(); i++){
            char Sch = s[i];
            char Tch = t[i];
            if(StoT.count(Sch) == true && StoT[Sch] != Tch){
                return false;
            }
            if(TtoS.count(Tch) == true && TtoS[Tch] != Sch){
                return false;
            }
            //not mapped yet?, map it
            StoT[Sch] = Tch;
            TtoS[Tch] = Sch;
        }
        return true;
    }
};