class Solution {
public:
    int binarysearch(vector<int>& nums,  int start, int target)
    {
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        while(end>=start)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                return 1; //found
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else //nums[mid]>target
            {
                end=mid-1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        //method 2:
        //we will sort it and then use binary search 
        //we know that nums[j]-nums[i]=k, hence, we can say that the target = k+nums[i]
        //so we will go through each element (nums[i]) and try to find out the target
        //if we r able to find out the target then we will store the pair ain the set as i!=j

        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for(int i=0;i<nums.size();i++)
        {
            if(binarysearch(nums, i+1, nums[i]+k)!=-1) //TARGET FOUND
            {
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
        
    }
};