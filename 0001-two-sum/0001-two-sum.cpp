class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indxs; 
        int i=0, j = nums.size()-1;

        while(i<j && j>=0){
                
                if(nums[i]+nums[j]==target){
                    indxs.push_back(i);
                    indxs.push_back(j);
                    break;
                }
                else{
                    i++;
                }
                
                if(i==j){
                i=0;
                j--;
            }
            
        }

        return indxs;  
    }
};