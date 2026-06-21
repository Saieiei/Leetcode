class Solution {
public:
    bool isIsomorphic(string s, string t){
        //we have to map them perfectly
        vector<int>StoT(26, -1);
        vector<int>TtoS(26, -1);
        //go through each letter
        for(int i=0; i<s.length(); i++){
            char Sch = s[i];
            char Tch = t[i];
            //check if they are not yet mapped
            if(StoT[Sch - 'a'] == -1 && TtoS[Tch - 'a'] == -1){
                //not yet mapped
                StoT[Sch - 'a'] = Tch - 'a';
                TtoS[Tch - 'a'] = Sch - 'a';
            }
            else{
                //its mapped already, check if it follows pattern
                if(StoT[Sch - 'a'] != Tch - 'a' || TtoS[Tch - 'a'] != Sch - 'a'){
                    return false;
                }

            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //same as isomorphic
        //bijection mapping using vectors
        //vectors because its only lowercase (26)
        //start the process
        vector<string> results;
        for(const string& word: words){
            //bc
            if(word.length() != pattern.length()){
                //not possible
                continue;
            }
            //check if this is a isomorphic or not
            if(isIsomorphic(word, pattern)){
                //save it
                results.push_back(word);
            }
        }
        return results;
    }
};