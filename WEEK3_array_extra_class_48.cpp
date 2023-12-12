#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main ()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    //transpose
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=i;j<matrix[i].size();j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //reverse each row
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    //print
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

// https://leetcode.com/problems/rotate-image/submissions/1118141883/