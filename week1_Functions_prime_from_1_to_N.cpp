#include<iostream>
using namespace std;

void prime(int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                break;
            }
        }
        if(i==j)
        {
            cout<<i<<endl;
        }
    
    }

}

int main ()
{
    int n;
    cin>>n;

    prime(n);
}