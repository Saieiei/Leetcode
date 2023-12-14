class Solution {
public:
    double SlidingWindow(vector<int>& nums, int& k)
    {
        int i=0;
        int j=k-1;

        int sum=0;
        int maxsum=INT_MIN;
        for(int x=i;x<=j;x++)
        {
            sum=sum+nums[x];
        }
        maxsum=sum;

        //catch part
        j++;

        while(j<nums.size())
        {
            sum=sum-nums[i++];
            sum=sum+nums[j++];
            maxsum=max(maxsum, sum);
        }

        double ans=maxsum/(double)k;
        return ans;



    }
    double findMaxAverage(vector<int>& nums, int k) {
        return SlidingWindow(nums, k);

        
    }
};