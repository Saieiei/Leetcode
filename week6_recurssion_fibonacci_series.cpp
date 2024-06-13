#include<iostream>
using namespace std;

int fibonacci(int n)
{
    //base case
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    //compute
    //recursion call
    int ans=fibonacci(n-1)+fibonacci(n-2);
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number for the fibonacci series: ";
    cin>>n;
    int ans = fibonacci(n);
    cout<<"Fibonacci series of "<<n<<" is: "<<ans<<endl;
    //0 1 1 2 3 5 8 13 21 34 55 89 144 233 377s
}