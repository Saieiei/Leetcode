#include<iostream>
using namespace std;

void factorial(int a)
{
    int fact=1;
    for(int i=1;i<=a;i++)
    {
        fact=fact*i;
    }
    cout<<fact;
}
int main()
{
    int a;
    cin>>a;

    factorial(a);
}