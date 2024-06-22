#include<iostream>
using namespace std;

void printPermutations(string &str, int index)
{

    //base case
    //ur index is basically ur i
    if(index>=str.length())
    {
        cout<<str<<" "<<endl;
        return;
    }

    //calculations
    for(int j=index; j<str.length(); j++)
    {
        swap(str[index], str[j]);
        //recursive call
        printPermutations(str, index+1);
        //backtrack (to restore the original string and helpful for time an space  ' &')
        swap(str[index], str[j]);
    }
}

int main()
{
    string str="abc";
    int index=0;
    printPermutations(str, index);
}