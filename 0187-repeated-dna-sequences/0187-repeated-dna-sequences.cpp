class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        const int windowSize = 10;
        //M2 - sorting 
        //nlogn
        //if we take each block of 10 and reorder thenm in sorted format
        //then the duplicates will be adjacent to each other
        //bc
        //if length is less than 10
        if(n<10){
            //not possible
            return {};
        }
        //if the legtn is equal to 10
        if(n==10){
            //still not possible
            return {};
        }
        vector<string>possibleSubStringsSorted;
        //push all the possible substrings
        for(int i=0; i<=(n-windowSize); i++){
            string SubString = s.substr(i, 10);
            possibleSubStringsSorted.push_back(SubString);
        }
        //now sort the entier vector
        sort(possibleSubStringsSorted.begin(), possibleSubStringsSorted.end());

        vector<string> ans;
        //now traverse through this sorting string and find out the dup adjacent once
        //if they r not inserted in the ans already, then push it in 
        for(int i=1; i<possibleSubStringsSorted.size(); i++){
            //check if the prev1 is duplicate
            if(possibleSubStringsSorted[i] == possibleSubStringsSorted[i-1]){
                //we found a matching 1 but pefore pushing it in ans, check its back once
                //for example ther can be 3 duplicates instead of 2
                if(ans.empty() || ans.back() != possibleSubStringsSorted[i]){
                    //its safe to push it in now
                    ans.push_back(possibleSubStringsSorted[i]);
                }
            }
        }
        return ans;
    }
};