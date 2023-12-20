#include<iostream>
using namespace std;
int main()
{
    int divisor, divident;
    //int quotient = 0;
    cin>>divident>>divisor;
    int dividentt=abs(divident);
    int divisorr=abs(divisor);

    //if(divisor*quotient==divident) cout<<quotient<<endl;
    //if(divisor*quotient>divident) we have to move left, end--; make sure to save the answer before moving left
    //if(divisor*quotient<divident) 

    int mid=0, start=0, end=dividentt, ans=0;
    mid=start+(end-start)/2;
    while(start<=end)
    {
        if(divisorr*mid==dividentt)
        {
            ans=mid;
            
            break;
        }
        else if(divisorr*mid>dividentt)
        {
            end=mid-1;
            mid=start+(end-start)/2;
        }
        else if(divisorr*mid<dividentt)
        {
            start=mid+1;
            ans=mid;
            mid=start+(end-start)/2;
        }
    }
    //we will handle the negative cases separately
    if(divident<0 && divisor>0 || divident>0 && divisor<0)
    {
        ans=-ans;
    }
    
    cout<<ans<<endl;
    
}