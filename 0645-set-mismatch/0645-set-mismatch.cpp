class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //we can try this by using a simple logic
        //basicailly we will compare it with with its index
        //1 2 2 3 4
        //0 1 2 3 4 
        //so we can see from here that the value of the nums should always be 1 less and it will be equal to index value
            //if not then that value is a duplicate value
        //and the missing value is always 1 above the duplicate value

        //vector<int> ans;

        //for(int i=0;i<nums.size();i++)
        //{
        //    if(nums[i]==i+1)
        //    {
        //        continue;
        //    }
        //    else
        //    {
        //        ans.push_back(nums[i]);
        //        ans.push_back(nums[i]+1);
        //        break;
        //    }
        //}

        //return ans;
        //the above logic will work if it strictly starts from 1

     


        int n =nums.size();
        vector<int>v(n+1,0);
        int missing=0,duplicate =0;
        for(int i =0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i =1;i<v.size();i++){
            if(v[i]==2)duplicate = i;
            if(v[i]==0)missing = i;
        }
        return {duplicate,missing};
    }
}; 





