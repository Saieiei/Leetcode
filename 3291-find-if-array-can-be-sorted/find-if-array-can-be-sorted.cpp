class Solution {
public:
    int setBits(int n)
    {
        //we need to find the number of 1's from the binary form
        int count =0;
        while(n)
        {
            n = n & (n-1);
            count++;
        }
        return count;

    }
    bool canSortArray(vector<int>& nums) {
        //we will be using bubble sort method
        //becuase it does checking with the adjacent values only
        //now to check the set bits we will use a function
        int n = nums.size();
       
        //bubble sort
        for(int i=1; i<n; i++) //no of comparison to be made
        {
            for(int j=0; j<n-i; j++) //this is where we will start comparing from 0th index, and limiting it with i, because we know during each phase 1 element gets settled
            {
                if(nums[j] > nums[j+1])
                {
                    //check the set bits
                    if(setBits(nums[j])==setBits(nums[j+1]))
                    {
                        swap(nums[j], nums[j+1]);
                    }
                    else
                    {
                        return false;
                    }
                }

            }
        }
        return true;

    }
};