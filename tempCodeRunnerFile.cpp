sort(nums.begin(), nums.end());
    int i=0, j=nums.size()-1;
    while(i<j)
    {
        if(nums[i]+nums[j]==target)
        {
            cout<<"["<<i<<","<<j<<"]";
            break;
        }
        else if(nums[i]+nums[j]<target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }