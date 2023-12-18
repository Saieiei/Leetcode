#include<iostream>
using namespace std;

int binary_search_1st_element(int arr[], int& n, int& target)
{
    int start=0; //1st index
    int end=n-1; //last index;
    int mid=(start+end)/2; //mid index
    int ans=-1;
    while(start<=end) //<= is imp
    {
        if(arr[mid]==target)
        {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]>target)
        {
            end=mid-1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return ans;
}


int main()
{
    int arr[]= {10,20,30,30,30,30,40,50};
    int n =8;
    int target = 30;
    int ans=binary_search_1st_element(arr,n,target);
    if(ans==-1)
    {
        cout<<"Not Found";
    }
    else
    {
        cout<<"Found at index "<<ans<<endl;
    }
}