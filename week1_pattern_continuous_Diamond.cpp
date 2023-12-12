#include <iostream>
using namespace std;
int main()
{
    int num; //num=number of rows
    cin >> num;
    int n=num/2;
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
    for(int r=0;r<n;r++) //r=rows
    {
        int space=r;
        for(int sp=0;sp<space;sp++)
        {
            cout << " ";
        }
        for(int s=0;s<n-r;s++) //s=stars
        {
            cout << "* ";
        }
        cout << endl;
    }
        
}
