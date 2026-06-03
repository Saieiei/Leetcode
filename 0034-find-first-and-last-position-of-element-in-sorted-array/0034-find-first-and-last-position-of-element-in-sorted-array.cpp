class Solution {
public:
    void BS(int low, int high, const vector<int>& nums, const int& target, const bool& leftOnly1st, vector<int>& ans){
        //start the process
        //should we move to left side or right side
        //move to left side
        while(low <= high){
            int mid = low + (high - low)/2;
            int midEle = nums[mid];
            if(midEle == target){
                //move it to left or right?
                if(leftOnly1st == true){
                    //move it to leftside
                    ans[0] = mid;
                    high = mid -1;
                }
                else{
                    //move it to rightSide
                    ans[1] = mid;
                    low = mid + 1;
                }
            }
            //we still cant end it
            else{
                if(midEle > target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        //BS will 1st check the mid element
        //we cannot predict left or right position of target
        //so 1st we have the find the left element
        //we will do BS and get the element
        //then if we get the target we willmove high to mid -1;
        //then start BS again to check if we can find the target and so on
        //teh same goes for right, so basically 2 BS operation
        //2Logn = logn

        int low = 0;
        int high = n-1;
        bool leftOnly1st = true;
        vector<int> ans(2, -1); //-1, -1
        BS(low, high, nums, target, leftOnly1st, ans);
        //if no change in left side, we cant find that element
        if(ans[0] == -1){
            return ans;
        }
        leftOnly1st = false;
        BS(low, high, nums, target, leftOnly1st, ans);
        return ans;
    }
};