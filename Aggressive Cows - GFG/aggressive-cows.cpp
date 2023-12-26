//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//week4_ass
//binary search
class Solution {
public:


    bool possibleSolution(vector<int>& stalls, int n, int k, int sol)
    {
        //here we have to try to fit in the cows within the given gap(sol)
        // we have to make sure that we fit in all the cows
        int c=1;
        //lets consider the 1st cows pos
        int pos=stalls[0];
        //now we will try to keep the cows with all the possible stalls and see if it can fit in within the given gap
        for(int i=1; i<n;i++)
        {
            //we will check if the gap between the cows is is greater(atlest) the given sol(mid)
            if(stalls[i]-pos>=sol) //if so we will place the cow and update the new position of the currect cow
            {
                c++;
                pos=stalls[i];
            }
            if(c==k) //if we have successfully placed all the cows within(atleast) the given gap then the gap is a possible sol
            {
                return true;
            }
            
        }
        return false;
    }
    



    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        //stalls is not soerted so 1st we will sort that and then appply biinary search on it
        sort(stalls.begin(), stalls.end());
        //now we will define the search space, searchSpace is basiaclly the maximum possible gap u can keep the cows at 
        //then we will slowly try to increase the gap by moving the to start = mid+1
        //this value maynot actally be present in the stalls gap it its based on atleast condition
        int start=0;
        int end=stalls[n-1]-stalls[0];
        int ans=0;
        int mid=start+(end-start)/2;
        //applying binary search
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(possibleSolution(stalls, n, k, mid))// if we find out that the gap(middle element) can accumulate then we will save that ans 
            {
                //but we need to find the maximum possible distance so we have to move the domain(searchSpace) to the right where the gap is more
                ans=mid;
                start=mid+1;
            }
            else // if we r not able to accomodate the cows within the give gap(middle element) then we have to decrease the gap as ther is more chances for 1 cow to be next to another cow 
                // where the gap is just 1, so we sill shift the domain(searchSpace) to the left 
            {
                end=mid-1;
            }
        }
        return ans;
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends