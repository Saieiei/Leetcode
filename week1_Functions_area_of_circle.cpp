#include<iostream>
using namespace std;
void area_of_circle(int r)
{
    float area;
    area=3.14*r*r;
    cout<<area;
}
int main ()
{
    int r;
    cin>>r;

    area_of_circle(r);
}
