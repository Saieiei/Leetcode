#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int r=0;r<n;r++)
    {
        for(int col=0;col<n-r;col++)
        {
            if(r==0 || r==n-1)
                cout<<"*";
            else
            {
            if(col==0 || col==n-r-1)
                cout<<"*";
            else
             cout<<" ";
            }
           
        }
        cout<<endl;
    }
}

