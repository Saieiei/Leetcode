//very hard question

#include<iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;

    int condition=0;
    for(int r=0;r<n;r++)
    {
        if(r<=n/2)
        {
            condition=2*r;
        }
        else
        {
            condition=2*(n-r-1);
        }
        for(int c=0;c<=condition;c++)
        {
            if(c<=r)
            {
                cout<<c+1;
            }
            else
            {
                cout<<condition-c+1;
            }
           
        }
        cout<<endl;
    }
    
}

//very hard question
