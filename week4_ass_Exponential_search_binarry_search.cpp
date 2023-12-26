#include<iostream>
using namespace std;

int bin_search(int a[], int start, int end, int target)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==target)
        {
            return mid;
        }
        else if(a[mid]>target)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}

int expo_search(int a[], int n, int target)
{
    if(target==a[0])
    {
        return 0;
    }
    int i=1;
    while(i<n && a[i]<=target)
    {
        i=i*2;
    }
    int start=i/2;
    int end=min(i,n-1);

    return bin_search(a,start,end,target);
}

int main()
{
    int a[]={3,4,5,6,11,13,14,15,56,70};
    int n=sizeof(a);
    int trager=13;
    int ans=expo_search(a,n,trager);
    cout<<ans<<endl;

}
// this type of searching is useful when the array size is too big and the element if found near the start of the array or at the end of the array. Binnarry search is useful when the element is found in the middle of the array.
//so 1st we will find the required range from the very long array and then we will apply the binarry search in that range only.
//the array is sorted only.