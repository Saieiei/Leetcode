class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0;
        int rightsum=0;
        int pivot=-1;
        int flag=0;
        for(int i=0;i<nums.size();i++) //pivot index
        {
            if(i>0)
                leftsum+=nums[i-1];
            for(int j=i+1;j<nums.size();j++)
            {
                rightsum+=nums[j];
            }
            if(leftsum==rightsum)
            {
                pivot=i;
                flag=1;
                break;
            }
            else
            {
                rightsum=0;
            }

        }
        if (flag == 1)
        {
            return pivot;
        }
        else
        {
            return -1;
        }
    }
};