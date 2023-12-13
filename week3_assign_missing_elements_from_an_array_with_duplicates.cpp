#include <iostream>
using namespace std;

void findMissing1(int *arr, int n)
{
    //M1 visiting method (marking the elements as negative)
    for(int i=0;i<n;i++)
    {
        int index=abs(arr[i]);

        //checking if already visited or not
        if(arr[index-1]>0) //if not visited
        {
            arr[index-1]=-arr[index-1]; //make the element negative
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0) //not negative hence not visited hence missing
        {
            cout<<i+1<<" ";
        }
    }
    //O(n)
    //O(1)

}

void findMissing2(int *arr, int n)
{
    //sorting + swaping //dont use forloop because it should increment just like that
    int i=0;
    while(i<n)
    {
        int index=arr[i]-1;
        if(arr[i]!=arr[index])
        {
            swap(arr[i],arr[index]);
        }
        else
        {
            i++;
        }
    }
    //checking
    //for(int i=0;i<n;i++)
    //{
    //    cout<<arr[i]<<" ";
    //}
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)
        {
            cout<<i+1<<" ";
        }
    }
}


int main()
{
    int arr[] = {1,3,5,3,4};
    int n=5;

    //M1 visiting method
    //findMissing1(arr, n);

    //M2 sorting + swaping
    findMissing2(arr, n);


}