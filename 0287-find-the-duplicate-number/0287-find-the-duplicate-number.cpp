class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //M1 brute force, sort
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        for(int i=0; i<n-1; i++){
            j = i+1;
            if(nums[i] == nums[j]){
                return nums[i];
            }
        }
        //else
        return 0;
        
    }
};