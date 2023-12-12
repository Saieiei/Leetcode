#include <iostream>
#include <climits>

using namespace std;


int main() {
    int nums[] = {1,8,5,4,10,2,6,1,1,1,9};
    int size = sizeof(nums) / sizeof(nums[0]);

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int temp=0;
    int pos=0;

    for (int i = 0; i < size; i++) 
    {
        if (nums[i] >= max1) 
        {
            max1 = nums[i];
            if(pos<i && temp>max2)
            {
                max2=temp;
            }
            temp=max1;
            pos=i;
        }
        else{
            if(max2<nums[i])
            {
                max2=nums[i];
            }
        }
        
        
    }
    cout<<(max1-1)*(max2-1);

    return 0;
}
 // https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
