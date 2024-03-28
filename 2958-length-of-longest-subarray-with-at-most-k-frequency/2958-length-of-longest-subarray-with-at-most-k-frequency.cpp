//https://www.youtube.com/watch?v=OkaGdh6MTsA&t=291s
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //1st we will create a hasp map which will help us to track the value of k 
        map<int, int> mp;
        int maxx=0, left=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            while(mp[nums[i]]>k)
            {
                mp[nums[left]]--;
                left++;
            }
            maxx=max(maxx, i-left+1); //subarrays(i-left+1)
        }
        return maxx;
    }
};