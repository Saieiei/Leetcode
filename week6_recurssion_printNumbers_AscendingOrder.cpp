#include<iostream>
using namespace std;

void ascendingOrder(int n)
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
        //recurssion call
        ascendingOrder(n-1);
        cout<<n<<" ";
       
        
    }

}

int main()
{
    int n;
    cout<<"Enter the number to print in ascending order: ";
    cin>>n;
    cout<<"Numbers in ascending order are: ";
    ascendingOrder(n);
}