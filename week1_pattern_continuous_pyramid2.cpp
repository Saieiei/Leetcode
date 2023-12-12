#include<iostream>
using namespace std;
int main()
{
    int n; //n=size
    cin >> n;
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