//in this we will be using exclude, include principle
//to understand this better, u must must watch the video
#include<iostream>
using namespace std;

void substrings(string str, int n, string output, int index)
{
    //base case
    if(index==n)//finished
    {
        cout<<"-> "<< output << endl;
        return;
    }
    //test conditions
    //recurssion

    //1st we will do exclusing because if we do 1st inclusding then later on we also have to remove the elemt
    //instead 1st do excluding, then after all the exclusing part is done
    //u can simpy do including where u can add the elements and so on


    //excluding
    substrings(str, n, output, index+1);

    //including
    output.push_back(str[index]);
    substrings(str, n, output, index+1);
}

int main()
{
    string str="ABC";
    string output="";
    int index=0;
    int n=str.length();
    substrings(str, n, output, index);
}
