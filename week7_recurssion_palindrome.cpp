#include<iostream>
using namespace std;

bool palindromeRE(string &s, int start, int end)
{
    //base condition
    if(start>=end)
    {
        return true;
    }

    //conditions
    if(s[start]!=s[end])
    {
        return false;
    }

    //recurssion for the rest
    return palindromeRE(s, start+1, end-1);
    
}

int main()
{
    string s;
    cin>>s;
    if(palindromeRE(s, 0, s.size()-1))
    {
        cout<<"Yes, it is a palindrome"<<endl;
    }
    else
    {
        cout<<"No, it is not a palindrome"<<endl;
    }
}