#include <iostream>
using namespace std;
int main()
{
    int num; //num=number of rows
    cin >> num;
    int n=num/2;
    for(int r=0;r<n;r++) //r=rows
    {
        for(int c=0;c<n-r-1;c++)
        {
            cout << " ";
        }
        for(int c=0;c<=r;c++) //s=stars
        {
            if(c==0 || c==r)
            cout << "* ";
            else
            cout << "  ";
        }
        cout << endl;
    }
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
