#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int r=0;r<n;r++)
    {
        //star
        for(int i=0;i<2*n-r-2;i++)
        {
            cout<<"*";
        }
        //number
        for(int c=0;c<2*r+1;c++)
        {
            if(c%2==0)
            {
                cout<<r+1;
            }
            else
            {
                cout<<"*";
            }
        }
        //star
        for(int i=0;i<2*n-r-2;i++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}