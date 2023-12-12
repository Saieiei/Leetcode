#include<iostream>
using namespace std;

void convert(float fahrenheit)
{
    float celsius;
    celsius=(fahrenheit-32)*5/9;
    cout<<"The temperature in celsius is: "<<celsius<<endl;
}

int main ()
{
    float fahrenheit;
    cout<<"Enter the temperature in fahrenheit: ";
    cin>>fahrenheit;
    convert(fahrenheit);
}