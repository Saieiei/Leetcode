#include<iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;

    int counter=1;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<r+1;c++)
        {
            cout<<counter;
            counter++;

            if(c<r)
            {
                cout<<"*"; 
            }
        }
        cout<<endl;
    }
    
    for(int r=0;r<n;r++)
    {
        int start =counter-(n-(r+1)+1);
        counter=start;
        for(int c=0;c<n-r;c++)
        {
            cout<<start;
            start++;

            if(c<n-r-1)
            {
                cout<<"*"; 
            }
        }
        cout<<endl;
    }
}