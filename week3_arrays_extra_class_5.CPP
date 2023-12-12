#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main ()
{
    vector<vector<int>> mat{{0,0},{1,1},{0,0}};
    vector<int> ans;
    int count1=INT_MIN;
    int rownumber=INT_MIN;

    for(int i=0;i<mat.size();i++)
    {
        int count=0;
        for(int j=0;j<mat[i].size();j++)
        {
            if(mat[i][j]==1)
                count++;
        }
        if(count>count1)
        {
            count1=count;
            rownumber=i;
        }
    }
    ans.push_back(rownumber);
    ans.push_back(count1);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}