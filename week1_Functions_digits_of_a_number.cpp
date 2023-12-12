#include<iostream>
using namespace std;

//void digits_of_a_number(int n)
//{
//    int x=n;
//    while(x>0)
//    {
//        int r=x%10;
//        cout<<r<<endl;
//        x=x/10;
//    }
//}

void digits_of_a_number(int n)
{
    int x=n;
    int count=0;
    while(x>0)
    {
        x=x/10;
        count++;
    }
    int div=1;
    for(int i=1;i<count;i++)
    {
        div=div*10;
    }
    while(div>0)
    {
        int q=n/div;
        cout<<q<<endl;
        n=n%div;
        div=div/10;
    }
}

int main()
{
    int n;
    cin>>n;

    digits_of_a_number(n);
}