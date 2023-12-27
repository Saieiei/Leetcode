#include<iostream>
using namespace std;

  void convertCharcter(char ch[], int len)
  {
    int i=0;
    while(ch[i]!='\0')
    {
        if(ch[i]=='@')
        {
          ch[i]=' ';
        }
        i++;
    }
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
  convertCharcter(ch , len);
  cout<<ch<<endl;

}