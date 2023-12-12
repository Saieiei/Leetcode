#include<iostream>
using namespace std;

void convertion(float km)
{
    float miles;
    miles=km*0.621371;
    cout<<"The distance in miles is: "<<miles<<endl;
}


int main ()
{
    float km;
    cout<<"Enter the distance in km: ";
    cin>>km;
    convertion(km);
}