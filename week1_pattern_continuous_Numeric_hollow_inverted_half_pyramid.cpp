#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int r=0;r<n;r++)
    {
        for(int c=0;c<r+1;c++)
        {
            if(r==0)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<i+1;
                }
            }
            else if(r==(n-1))
            {
                cout<<n;
                break;
            }
            else
            {
                cout<<r+1;
                for(int i=0;i<n-3+1-r;i++)
                {
                    cout<<" ";
                }
                cout<<n;
                break;
            }

        }
        cout<<endl;
    }
}