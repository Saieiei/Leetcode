class Solution {
public:
    int rob(vector<int>& nums) {
        //its simple 
        //1st we will innititalise the 1st value and the 2nd value in a new array(arr)
        //now we will start the for loop for 2(cuz 0 and 1 r already filled)
            //we will assign arr[2] as the max value between [nums[2]+nums[2-2] or nums[1]]
            //(either we can chose to accept the new value or reject the new value based on the maximum, if its more than maximum take it in the arr, else ditch that value and go ahead)
            //This is basically DP, its little hard to understand, but its linear in time
            //the final ans will be in the end
            //https://www.youtube.com/watch?v=LCtzDl1uT_U

            //we also have to set some cutoffs where if there is only 1 house then rob that and return the value immediately
            if(nums.size()==1)
            {
                return nums[0];
            }

        vector<int> arr(nums.size(), 0); //dp
        arr[0]=nums[0];
        arr[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++)
        {
            arr[i]=max(nums[i]+arr[i-2], arr[i-1]);
        }

        return arr[nums.size()-1];


        
    }
};