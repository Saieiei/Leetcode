#include<iostream>
using namespace std;

void colwisesum(int arr[][3], int n)
{
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
}


int main ()
{
    int n;
    cin>>n;

    int arr[n][3];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    
    colwisesum(arr, n);

}