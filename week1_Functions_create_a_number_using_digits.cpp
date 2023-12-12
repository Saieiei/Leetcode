#include<iostream>
using namespace std;

void create_a_number_using_digits(int n)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        x=x*10+d;
    
    }
    cout<<x<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of digits u wish to enter:\n";
    cin>>n;
    create_a_number_using_digits(n);

}