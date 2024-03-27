//https://www.youtube.com/watch?v=A95JYw5yFUg
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0; //this is the base conditon as no 2 diff elements can give the k as 1
        //we will use the concept of 2 pointers or variable sliding window
        int ans=0, left=0, product=1;
        //ur right is i in the for loop
        for(int i=0;i<nums.size();i++)
        {
            product=product*nums[i];
            while(product>=k)
            {
                product=product/nums[left];
                left++;
            }
            ans+=i-left+1; //(to calculate the number of subarrays this is the formula, right - left + 1)
        }
        return ans;
        
    }
};