#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    int size = nums.size();
    int flag = 0;

    vector<int> positive;
    vector<int> negative;


    for(int i=0;i<size;i++)
    {
        if(nums[i]>=0)
        {
            positive.push_back(nums[i]);
        }
        else
        {
            negative.push_back(nums[i]);
        }
    }
    int i=0;
    int p=0,n=0;
    while(i<size)
    {
        nums[i]=positive[p];
        p++;
        i++;
        nums[i]=negative[n];
        n++;
        i++;
    }
    for(int i=0;i<size;i++)
    {
        cout<<nums[i]<<" ";
    }
}

// https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/1118019387/