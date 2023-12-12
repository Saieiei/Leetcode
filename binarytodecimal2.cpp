#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int binary=0;
    cin>>binary;
    int decimal=0;
    int i=0;
    
    while (binary>0)
    {
        
        int remainder=binary%10;
        decimal=decimal+remainder*pow(2,i++);
        binary=binary/10;
    }
    cout<<decimal<<endl;

}