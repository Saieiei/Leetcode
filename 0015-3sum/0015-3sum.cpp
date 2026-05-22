class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //sort it 1st
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //traverse through the array now
        for(int i=0; i<n; i++){
            //remove duplicates
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            //now we have a new num
            int leftIndex = i+1;
            int rightIndex = n-1;
            while(leftIndex < rightIndex){
                int sum = nums[i] + nums[leftIndex] + nums[rightIndex];
                if(sum == 0){
                    //found it
                    ans.push_back({nums[i], nums[leftIndex], nums[rightIndex]});
                    while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex + 1]){
                        leftIndex++;
                    }
                    while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex - 1]){
                        rightIndex--;
                    }
                    leftIndex++;
                    rightIndex--;
                }
                else if(sum > 0){
                    //move right index inside
                    rightIndex = rightIndex - 1;
                }
                else{
                    //move left index outside
                    leftIndex = leftIndex + 1;
                }
            }
        }
        return ans;
    }
};