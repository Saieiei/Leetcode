class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //sorting
        sort(nums.begin(), nums.end());
        //2 pairs method
        int i=0, j=1;
        //we will use 'set and pair' to store the unique pairs
        set<pair<int,int>> ans;
        int n=nums.size();
        // this is for the test case where nums=[1] so no possible solution
        if(n==1)
            return 0;
        int diff=abs(nums[j]-nums[i]);
        while(i < n && j < n)
        {
            diff=abs(nums[j]-nums[i]);
            if(diff==k)
            {
                ans.insert({nums[i], nums[j]});
                i++, j++;
            }
            else if(diff>k) //the diff is high, so to lower it we need to move i to right side
            { 
                i++;
            }
            else //diff<k, teh diff is low, so to increase it we need to more j to right side
                j++;
            if(i==j) //it is mentioned in teh conditions
                j++;
        }
        int answer=ans.size();
        return answer;
        
    }
};