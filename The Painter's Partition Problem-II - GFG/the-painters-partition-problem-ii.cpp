//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//week4_ass
//same as book allocation problem GFG
class Solution
{
  public:
    
    bool possibleSolution(int arr[], int n, int k, long long sol)
    {
        long long timeSum=0;
        int c=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>sol)
                return false;
            if(timeSum+arr[i]>sol)
            {
                c++;
                timeSum=arr[i];
                if(c>k)
                    return false;
            }
            else
            {
                timeSum+=arr[i];
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        //if the number of painters is more than the number of boards then we cant do it
        //if(k>n) return -1;
        
        //1st we neef to define space search index
        long long start=0;
        long long end=0;
        long long ans=0;
        
        //u can use accumulate function also int sum = accumulate(arr.begin(), arr.end(), 0);
        for(int i=0;i<n;i++)
        {
            end+=arr[i];
        }
        //now we will use binary search wala function
        while(start<=end)
        {
            long long mid=start+(end-start)/2; //finding the mid index
            if(possibleSolution(arr, n, k, mid)) //found posible solution but we need a minimum solution
            {
                ans=mid;
                end=mid-1;
            }
            else //we coudnt find a soltion so we have to move left as the size increases(time) there r more chances
            {
                start=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends