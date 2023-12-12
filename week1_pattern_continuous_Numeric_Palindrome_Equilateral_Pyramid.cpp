#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int r=0;r<n;r++)
    {
        int x;
        for(int i=0;i<n-r-1;i++)
        {
            cout<<" ";
        }
        for(int c=0;c<r+1;c++)
        {
            cout<<c+1;
            x=c+1;
        }
        for(int i=1;i<=r;i++)
        {
            cout<<x-i;
        }
        cout<<endl;
    }
}