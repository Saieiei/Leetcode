//revrse a string using recurssion and 2 pointer approach
#include<iostream>
using namespace std;

void reverse_string(string &s, int start, int end)
{
    //base condition
    if(start>=end)
    {
        return;
    }
    //swap the start and end character
    swap(s[start], s[end]);
    //recurse for the remaining string
    reverse_string(s, start+1, end-1);

}

int main()
{
    string s = "Hello";
    reverse_string(s, 0, s.size()-1);
    cout<<s<<endl;
}