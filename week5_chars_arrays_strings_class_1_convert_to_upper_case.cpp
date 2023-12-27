#include<iostream>
using namespace std;

string convertToUpperCase(char ch[])
{
    int i=0;
    while(ch[i]!='\0')
    {
        if(ch[i]>='a' && ch[i]<='z')
        {
            ch[i]=ch[i]-'a'+ 'A'; 
        }
        i++;
    }
    return ch;
}

int main ()
{
    char ch[100];
    cin.getline(ch, 100);
    cout<<convertToUpperCase(ch)<<endl;
    
}
