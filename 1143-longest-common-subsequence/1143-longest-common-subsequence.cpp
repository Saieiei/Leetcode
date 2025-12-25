//M4 TabulationSO
//the idea is that if they match then move th eindex ahead by 1 fot both
//else we have to move either 1 cuz there is a posibility
    //now we have to move the index which was not moved before
//consider this test case string A = xyzabc, B = abcxyz, there r 2 possibolities, "abc" and "xyz"
//u will get "abc" if u move the A string index and u will get "xyz" if u move the B string index
//we will use recursion for the upcoming comparison
//make sure to take the max of the recursions
class Solution {
public:

    int recursionTabuSO(string& text1, string& text2, int index1, int index2){

        //1. create dp
        vector<int> curr(text1.length()+100);
        vector<int> next(text1.length()+100);
        //vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, 0)); //bc

        //2.for-loop, reversed, copy-paste, rec-fun, index
        for(int i=text1.size()-1; i>=0; i--){ //bc
            for(int j = text2.size()-1; j>=0; j--){ //bc

                int ans =0;
                if(text1[i] == text2[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    int pattern1 = curr[j+1];
                    int pattern2 = next[j];
                    ans = 0 + max(pattern1, pattern2);
                }
                //2. store the ans in dp
                curr[j] = ans;
            }
            //shifting
            next = curr; // its is goign upwards, reverded for loop
        }

        //3. return accordingly
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int index1=0, index2=0;
        //1. create dp
        //vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        return recursionTabuSO(text1, text2, index1, index2);
    }
};