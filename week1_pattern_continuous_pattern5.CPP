#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int r=0;r<n;r++)
    {
        char ch = 'A';
        char ch1 = 'A';
        for(int c=0;c<r+1;c++)
        {
            cout<<char(ch+c);
            ch1=char(ch+c);

        }
        for(int i=0;i<r;i++)
        {
            cout<<char(ch1-1-i);
        }
        cout<<endl;
    }
}