#include<iostream>
using namespace std;


void reverseString(char ch[], int len )
{
    int i=0;
    int j=len-1;
    while(i<j)
    {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

int lengthString(char ch[])
{
    int i=0;
    while(ch[i]!='\0')
    {
        i++;
    }
    return i;
}


int main ()
{
    char ch[100];
    cin.getline(ch, 100);
    //we need to have the length of the string
    int len=lengthString(ch);
    reverseString(ch, len);
    cout<<ch;
}