#include<iostream>
using namespace std;

void even_odd_using_bitwise_operator(int n)
{
    if(n&1) //if(n&1==1) is also correct
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;
}


int main ()
{
    int n;
    cin>>n;

    even_odd_using_bitwise_operator(n);
}