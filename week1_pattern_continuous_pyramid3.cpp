#include <iostream>
using namespace std;
int main()
{
    int n; //n=size
    cin >> n;
    for(int r=0;r<n;r++) //r=rows
    {
        for(int c=0;c<n-r-1;c++)
        {
            cout << " ";
        }
        for(int c=0;c<=r;c++) //c=columns
        {
            if (c==0 || c==r)
            cout << "* ";
            else
            cout << "  ";
        }
        cout << endl;
    }
}