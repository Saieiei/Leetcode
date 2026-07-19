class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        const int windowSize = 10;
        //M4 2 sets 
        //N, N (time and space optimized)
        //1 set is for seeing for teh 1st time
        //another set if for repeated
        //bc
        if(n <= windowSize){
            //not possible
            return {};
        }
        //2 sets
        unordered_set<string> seen;
        unordered_set<string> reported;
        vector<string> ans;
        //create every possible sub arrays
        for(int i=0; i<=(n - windowSize); i++){
            string subString = s.substr(i, windowSize);
            //check if we r seeing this substring for the 1st time ever
            if(seen.count(subString) == 0){
                //simply push it in as visisted
                seen.insert(subString);
            }
            else{
                //it was already seen, so we have to check if this is a duplicate
                //or too many duplicates
                if(reported.count(subString) == 0){
                    //1st duplicate only. we can push it in ans and mark it as visited
                    ans.push_back(subString);
                    reported.insert(subString);
                }
                else{
                    //its freq is more than 2, we can simply ignore it
                    continue;
                }
            }
        }
        return ans;
    }   
};