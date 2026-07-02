class Solution {
public:
    string removeDuplicates(string s, int k) {
        //vectors
        //N, N
        vector<pair<char, int>> countVec; //char, freq
        //traverse through the string
        for(const char& ch: s){
            //check is it matched with the previous 1
            if(!countVec.empty() && countVec.back().first == ch){
                //increase the freq
                countVec.back().second++;

                //since freq has increased, check if we met the condition
                if(countVec.back().second == k){
                    //pop it
                    countVec.pop_back();
                }
            }
            else{
                //empty or not matching
                countVec.push_back({ch, 1});
            }
        }
        //make the string now
        string ans = "";
        //pop it 1 by 1 then reverse it
        for(const pair<char, int>& it: countVec){
            char ch = it.first;
            int freq = it.second;
            while(freq){
                //very imp, do not do ans = ans + ch
                //u will go into memory issues
                ans += ch;
                freq--;
            }
        }
        return ans;
    }
};