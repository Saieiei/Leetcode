class Solution { //week3 assignments
public:
    int findDuplicate(vector<int>& nums) {

//
    //    sort(nums.begin(), nums.end());
//
    //    for(int i=0;i<nums.size()-1;i++)
    //    {
    //        if(nums[i]==nums[i+1])
    //        {
    //            return nums[i];
    //        }
    //    }
    //    return -1;


    //M2-makrking it has negative because the elemey=t should not be revisited

        //int ans=-1;
        //for(int i=0;i<nums.size();i++)
        //{
        //   int index = abs(nums[i]);
        //   if(nums[index]<0) //negative (marked already)
        //   {
        //       ans=index;
        //       break;
        //   }
        //   //else
        //  // {
        //       nums[index]*=-1;
        //   //}
        //}
        //return ans;




        //M3 this is easy but u need pen and paper, basically we r going to return the 0th element if its value is already present in the indexed place, we r able to do thos because the condition says N+1 integers so u can know that the ans is at 0th index.

        while(nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
   
};