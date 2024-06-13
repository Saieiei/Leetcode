#include<iostream>
using namespace std;

bool array_checker(int arr[], int n, int index)
{
    //base case
    //if we r able come till the end that is
    if(index==n)
    {
        return true;
    }
    //test condition
    //recurssion case
    if(arr[index-1]>arr[index])
    {
        return false;
    }
    else
    return array_checker(arr, n, index+1);
}

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index=0;
    if(array_checker(arr, n, index+1)) //we r passing index into this array because we will comepare it with the previos elements
    {
        cout<<"Array is in sorted order";
    }
    else
    {
        cout<<"Array is not in sorted order";
    }
}