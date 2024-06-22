#include<iostream>
using namespace std;

void subarrayRE(int arr[], int start, int end)
{
    //base condition
    if(start==end)
    {
        return;
    }
    //conditions
    for(int i =start; i<end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //recurssion for the rest
    subarrayRE(arr, start+1, end);
}
int main()
{
    int arr[]={1, 2, 3, 4, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        subarrayRE(arr, i, n);
    }
}