#include <iostream>
using namespace std;
int main()
{
    int n; //n=size
    cin >> n;
    for(int r=0;r<n;r++) //r=rows
    {
        int space=n-r-1;
        for(int j=0;j<space;j++)
        {
            cout << " ";
        }
        for(int s=0;s<=r;s++) //s=stars
        {
            cout << "* ";
        }
        cout << endl;
    }
}