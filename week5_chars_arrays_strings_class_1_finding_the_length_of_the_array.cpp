#include<iostream>
using namespace std;

int findLength(char ch[], int n)
{
    int i=0;
    while(ch[i]!='\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char ch[100];
    cin.getline(ch, 100);
    cout<< findLength(ch , 100);
}
