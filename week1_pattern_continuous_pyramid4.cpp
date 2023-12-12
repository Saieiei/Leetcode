#include<iostream>
using namespace std;
int main()
{
    int n; //n=size
    cin >> n;
    for(int r=0;r<n;r++) //r=rows
    {
        for(int c=0;c<r;c++) //c=columns
        {
            cout << " ";
        }
        for(int c=0;c<n-r;c++)
        {
            if(c==0 || c==n-r-1)
            cout << "* ";
            else 
            cout << "  ";
        }
        cout << endl;
    }
        
}