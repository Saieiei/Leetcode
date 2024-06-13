#include<iostream>
using namespace std;

int power(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    //compute
    else{
        //recursion call
        int ans=2*power(n-1);
        return ans;
    }
}

int main()
{
    int n;
    cout<<"Enter the power: ";
    cin>>n;
    int ans = power(n);
    cout<<"2^"<<n<<" is: "<<ans<<endl;
}