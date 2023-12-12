#include<iostream>
using namespace std;

void shiftby2(int arr[], int n)
{
    int temp1=arr[n-2];
    int temp2=arr[n-1];

    for(int i=n-1;i>=(0+2);i--)
    {
        arr[i]=arr[i-2];
    }
    arr[0]=temp1;
    arr[1]=temp2;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main ()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    shiftby2(arr,n);
}