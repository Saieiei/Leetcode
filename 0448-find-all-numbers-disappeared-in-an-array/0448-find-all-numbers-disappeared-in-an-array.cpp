class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            int index=nums[i]-1;
            if(nums[i]!=nums[index])
            {
                swap(nums[i],nums[index]);
            }
            else
            {
                i++;
            }
        }
        //checking
        //for(int i=0;i<n;i++)
        //{
        //    cout<<arr[i]<<" ";
        //}
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                ans.push_back(i+1);
                //cout<<i+1<<" ";
            }
        }
        return ans;
        
    }
};