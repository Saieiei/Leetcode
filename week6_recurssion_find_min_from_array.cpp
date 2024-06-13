#include<iostream>
#include<limits.h>

using namespace std;

void min_finder(int arr[], int n, int index, int &min)
{
    //base case
    if(index >= n)
    {
        return;
    }
    //compute
    if(arr[index] < min)
    {
        min = arr[index];
    }
    //recursion call
    min_finder(arr, n, index + 1, min);
}

int main()
{
    int arr[] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = 0;
    int min = INT_MAX;

    min_finder(arr, n, index, min);  
    cout << "Minimum value in the array is: " << min << endl;

    return 0;
}
