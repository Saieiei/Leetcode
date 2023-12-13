#include<iostream>
#include<vector>
using namespace std;

void moveNegativeToTheLeft(vector<int> &nums,int n) //2pointer approach
{
    int l=0;
    int r=n-1;

    while(l<r)
    {
        if(nums[l]<0)
        {
            l++;
        }
        else if(nums[r]>0)
        {
            r--;
        }
        else
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        
    }

    
}
int main ()
{
    vector<int> nums={1,2,-3,4,-5,6};
    int n=nums.size();
    moveNegativeToTheLeft(nums,n);    
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}