//we will 1st sort, 2nd pivot 1 and use 2 pointers
//removing the duplicates is the main task here
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //size cannot be less than 3
        //index is the pivot
        for(int index=0; index<n; index++){
            // skip duplicates
            if (index > 0 && nums[index] == nums[index - 1]){
                continue;
            }
            int leftIndex = index+1;
            int rightIndex = n-1;
            while(leftIndex < rightIndex){
                int sum = nums[leftIndex] + nums[index] + nums[rightIndex];
                //if sum is < 0 we need to increase the leftIndex
                if(sum < 0){
                    leftIndex = leftIndex + 1;
                }
                //if sum is > 0 we need to decrease the rightIndex
                else if(sum > 0){
                    rightIndex = rightIndex - 1;
                }
                else{
                    //we got a match
                    vector<int> temp{nums[leftIndex], nums[index], nums[rightIndex]};
                    ans.push_back(temp);
                    //process until we remove upcoming duplicates
                    while(leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex + 1]){
                        leftIndex++;
                    }
                    while(leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex - 1]){
                        rightIndex--;
                    }
                    //after u have pushed, update the pointers
                    leftIndex++;
                    rightIndex--;
                }
            }
        }
        return ans;
    }
};