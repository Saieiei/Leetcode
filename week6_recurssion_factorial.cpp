#include<iostream>
using namespace std;

int factorial_recurssion(int n)
{
    //base case/condition  
    int ans=1; 
    if(n==1)
    {
        return 1;
    }
    //compute
    else
    {
        //recurssion call
        ans=n*factorial_recurssion(n-1);
        return ans;
    }
}
int main()
{
    int n;
    cout<<"Enter the number for which u wish to find factorial: ";
    cin>>n;
    int ans=factorial_recurssion(n);
    cout<<"Factorial of "<<n<<" is: "<<ans<<endl;
}