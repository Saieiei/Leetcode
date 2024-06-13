#include<iostream>
#include<vector>

using namespace std;

void double_calc(int arr[], int n, int index)
{
    //base condition
    if(index>=n)
    {
        return;
    }
    //compute
    arr[index]= arr[index]*2;
    //recursion call
    double_calc(arr, n, index+1);
}
int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index=0;

    double_calc(arr, n, index);

    //display the double elements
    for(auto i:arr)
    {
        cout<<i<<" ";    
    }

}