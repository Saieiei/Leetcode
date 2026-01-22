//M1 Recursion
//do LIS from left to right and right to left and save its size/index
//calculate lis[i]+lds[size-i-1] -1
//calc the max size of the above formula
//return it by subtracting total - max size of the above formula
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, vector<int>& lis) {
        if(nums.size() == 0) return 0;

        vector<int> ans;
        ans.push_back(nums[0]);
        lis.push_back(1); //initial size after pushing nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
                lis.push_back(ans.size()); //update size 
            } 
            else{
                int indexSwitcher = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[indexSwitcher] = nums[i];
                lis.push_back(indexSwitcher + 1); //idk y or how
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis; vector<int>lds;
        lengthOfLIS(nums, lis); 
        reverse(nums.begin(), nums.end()); //reverse it for lds
        lengthOfLIS(nums, lds);

        //to find the latrgest mountain, we will track it INT_MIN, no need of vectors
        int largestMountainSize = INT_MIN;
        for(int i = 0; i < nums.size(); i++){ //remember that nums is reversed
            if(lis[i] == 1 || lds[nums.size() - i - 1] == 1) continue; //we dont consider
            largestMountainSize = max(largestMountainSize, lis[i] + lds[nums.size() -i -1] -1);
        }

        int minimalRemovals = nums.size() - largestMountainSize;
        return minimalRemovals;

    }
};