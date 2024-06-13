#include<iostream>
using namespace std;

void decendingOrder(int n)
{
    //base case
    if(n==0)
    {
        cout<<n<<" ";
        return ;
    }
    //compute
    else
    {
        cout<<n<<" ";
        //recurssion call
        decendingOrder(n-1);
    }

}

int main()
{
    int n;
    cout<<"Enter the number to print in decending order: ";
    cin>>n;
    cout<<"Numbers in decending order are: ";
    decendingOrder(n);
}