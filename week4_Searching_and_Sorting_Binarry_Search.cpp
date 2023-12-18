#include<iostream>
using namespace std;

int Binarry_search(int arr[10], int& n, int& target)
{
    int start=0; //index
    int end=n-1; //index
    int mid=(start+end)/2; //index
    while(start<=end)
    {
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(target>arr[mid])
        {
            start=mid+1;
        }
        else if(target<arr[mid])
        {
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;

}

int main()
{
    int arr[]= {1,2,3,4,5,6,7,8,9,10};
    int n =10;
    int target = 10;
    int key=Binarry_search(arr,n,target);
    if(key==-1)
    {
        cout<<"Not Found";
    }
    else
    {
        cout<<"Found at index "<<key<<endl;
    }
}