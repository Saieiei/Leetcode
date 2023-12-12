#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int decimal=0;
    cin>>decimal;
    int binary=0;
    int i=0;
    while (decimal>0)
    {
        int last_bit=decimal&1;
        binary=binary+last_bit*pow(10,i++);
        decimal=decimal>>1;
    }
    cout<<binary<<endl;

}