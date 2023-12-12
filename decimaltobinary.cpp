#include <iostream>
#include <cmath>

using namespace std;

int DecimalToBinary(int x)
    {
        int decimalNumber=x;
        int binaryNumber=0; //result to return
       
        int i=0;
        while(decimalNumber!=0)
        {
            int remainder=decimalNumber%2;
            binaryNumber=binaryNumber+remainder*pow(10,i++);
            decimalNumber=decimalNumber/2;
        }
        return binaryNumber;
    }

int main()
{
    

    int x;
    cout<<"Enter a number to convert it to binary: ";
    cin>>x;
    int binaryValue=DecimalToBinary(x);
    cout<<"The binary of "<<x<<" is: "<<binaryValue<<endl;
}