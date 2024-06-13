#include<iostream>
#include<vector>

using namespace std;

void even_calc(int arr[], int n, int index, vector<int> &ans)
{
    //base condition
    if(index>=n)
    {
        return;
    }
    //compute
    if(arr[index]%2==0)
    {
        ans.push_back(arr[index]);
    }
    //recursion call
    even_calc(arr, n, index+1, ans);
}
int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index=0;
    vector<int> ans;

    even_calc(arr, n, index, ans);

    //display only even elements
    for(auto i:ans)
    {
        cout<<i<<" ";    
    }

}