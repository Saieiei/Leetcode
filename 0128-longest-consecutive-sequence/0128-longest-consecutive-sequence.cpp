class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        //optimial N
        //basecase
        if(nums.size() == 0){
            return 0;
        }
        //we will use set for O(1) look ups
        //and also avoid dups
        unordered_set<int> st(nums.begin(), nums.end());
        int currElemenet = 0;
        int currSequence = 1;
        int maxSequence = 1;
        //start to Traverse through the SET, not the original array
        for(int num : st){
            currElemenet = num;
            //we will only proceed if the previous element is not there
            //this is like an optimization and a catch
            if(st.find(currElemenet-1) == st.end()){
                //the prev element is not there
                currSequence = 1;
                currElemenet = num;
                //move forward and check
                while(st.find(currElemenet + 1) != st.end()) {
                    //found it, move forward
                    currElemenet++;
                    currSequence++;
                }
                // Update the maximum streak found so far
                maxSequence = max(maxSequence, currSequence);
            }
        }
        return maxSequence;
    }
};