#include<iostream>
using namespace std;
int main()
{
    int n; //n=size
    cin >> n;
    n=n/2;
    for(int r=0;r<n;r++)
    {
        //pyramid1
        for(int c=0;c<n-r;c++)
        {
            cout << "*";
        }
        //pyramid2
        for(int c=0;c<2*r+1;c++)
        {
            cout << " ";
        }
        //pyramid3
        for(int c=0;c<n-r;c++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for(int r=0;r<n;r++)
    {
        //pyramid1
        for(int c=0;c<r+1;c++)
        {
            cout << "*";
        }
        //pyramid2
        for(int c=0;c<2*n-2*r-1;c++)
        {
            cout << " ";
        }
        //pyramid3
        for(int c=0;c<r+1;c++)
        {
            cout << "*";
        }
        cout << endl;
    }

}