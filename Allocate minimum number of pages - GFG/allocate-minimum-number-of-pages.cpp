//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool possibleSolution(int A[], int N, int M, int sol)
    {
        int c=1; //keep it as 1 and not 0 because we starting it with the 1st person itself
        int pageSum=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]>sol) //the pages r too big 
            {
                return false;
            }
            if(pageSum+A[i]>sol)//checking the maximum possible of books that can be alloted to 1 person
            {
                c++; //allocating books to a new peson 
                pageSum=A[i]; //initialising it again for the new person
                if(c>M) //if the number of poeple has exceeded, its not a solution
                {
                    return false;
                }
            }
            else //more books can be added to the person
            {
                pageSum=pageSum+A[i]; 
            }
        }
        return true;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //1st we have to find the searching space
        int start=0;
        int end=accumulate(A, A+N, 0); //u can even use for loop to add all the elements of the array
        if(M>N) return -1; //if number of people is more than the number of books, there is no possible solution
        int ans=0;
        //now we shall use binary search to find the ans
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(possibleSolution(A, N, M, mid))
            {
                ans=mid;
                //but we need to find minal solution so we have to move left
                end=mid-1;
            }
            else //we were not bale to find a solution so we should move right as there is more chnaces for the pages to fit with a bigger number(pages to fit per person)
            {
                start=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends