#include<iostream>
using namespace std;

int binarry_search(int arr[], int n, int target, int start, int end)
{
    //base case
    if(start>end)
    {
        return -1;
    }
    //test condition
    //recurssion case
    int mid=start+(end-start)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    else if(arr[mid]>target)
    {
        
        end=mid-1;
        return binarry_search(arr, n, target, start, end);
    }
    else{
        start=mid+1;
        return binarry_search(arr, n, target, start, end);
    }
}

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=11;
    int start=0;
    int end=n-1;
    int result=binarry_search(arr, n, target, start, end);
    if(result!=-1)
    {
        cout<<"Element found in the array";
    }
    else
    {
        cout<<"Element not found in the array";
    }

}