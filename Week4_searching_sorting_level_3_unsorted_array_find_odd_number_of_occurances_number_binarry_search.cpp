#include<iostream>
using namespace std;
int main()
{
    int arr[]={10,10,2,2,5,5,2,2,5,5,20,20,11,11,10,10,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s=0, e=n-1, mid=s+(e-s)/2;
    while(s<=e)
    {
        if(s==e)
        {
            cout<<arr[s];
            break;
        }
        if(mid%2==0) //the middle index is even
        {
            //if we r on the left side of the ans then we need to move right by 2 steps
            if(arr[mid]==arr[mid+1])
            {
                s=mid+2;
                mid=s+(e-s)/2;
            }
            //if we r on the right side of the ans then we need to move left but there is a chance that, that element is itself the ans, because even index is where the answer lies
            else if(arr[mid]==arr[mid-1])
            {
                e=mid;
                mid=s+(e-s)/2;
            }
        }
        else //the middle index is odd
        {
            //if we r on the left side of the ans then we need to move right by 1 step
            if(arr[mid]==arr[mid-1])
            {
                s=mid+1;
                mid=s+(e-s)/2;
            }
            //if we r on the right side of the ans then we have to move left by 1 step
            else if(arr[mid]==arr[mid+1])
            {
                e=mid-1;
                mid=s+(e-s)/2;
            }
        }
    }
}