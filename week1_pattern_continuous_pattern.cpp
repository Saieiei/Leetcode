#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int r=0;r<n;r++)
    {
        for(int col=0;col<2*r+1;col++)
        {
            if(col%2==0)
            {
                cout<<r+1;
            }
            else
            {
                cout<<"*";
            }
            
        }
        cout<<endl;
    }

}

