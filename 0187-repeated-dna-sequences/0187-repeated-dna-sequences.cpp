class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        const int windowSize = 10;
        //M3 hashing (freq)
        //N, N
        //we will push in the ans only if the freq >=2
        //bc
        if(n <= windowSize){
            //not possible
            return {};
        }
        unordered_map<string, int> freqs;
        //make every possible substring and update the freq
        for(int i=0; i <= (n - windowSize); i++){
            string substring = s.substr(i, windowSize);
            //update the freq
            freqs[substring]++;
        }
        vector<string> ans;
        //now traverse through the freq of the unordered_map 
        //and push in the substrings whos frequency is >=2
        for(const pair<const string, const int>& it: freqs){
            string subString = it.first;
            int freq = it.second;
            //check if freq >=2
            if(freq >= 2){
                ans.push_back(subString);
            } 
        }
        return ans;
    }   
};