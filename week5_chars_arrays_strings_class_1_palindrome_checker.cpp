#include<iostream>
using namespace std;

bool palindrome(char ch[], int len)
{
    int i=0;
    int j=len-1;
    while(i<j)
    {
        if(ch[i]==ch[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main ()
{
  char ch[100];
  cin.getline(ch, 100);
  int len=0;
  while(ch[len]!='\0')
  {
      len++;
  }
  if(palindrome(ch, len))
  {
    cout<<"Palindrome"<<endl;
  }
  else
  {
    cout<<"Not Palindrome"<<endl;
  }

}