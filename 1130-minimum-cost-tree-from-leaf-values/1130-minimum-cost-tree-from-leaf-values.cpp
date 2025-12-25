//M2 Memoization
//to solve this we have to make every posible tree
//to do that we will iterate over the arr 1 by 1, dividing it into left and right half and find out the leaf nodes
//with the left half and right half we will find the max in each and multiply which will give us the non leaf values
//with recursion we will add up the non leafnode values
//then finally return the min of all those values
//so with the left half and right half we will return the mac using map and pair, u can do it unordered_map too, just that pair as a key is not accepted
//we will precompute the max of the all ranges and store it in the map for O(1) look up
class Solution {
public:

    int recursionMemo(vector<int>& arr, map<pair<int, int>, int>& mp, int left, int right, vector<vector<int>>& dp){

        //2. bc, check if its already present in the dp
        if(left == right) return 0; //its basically leaf node, and we dont consider them
        if(dp[left][right] != -1) return dp[left][right];
        int ans = INT_MAX;
        
        for(int i=left; i<right; i++){ //<right because i+1 can cause overflow
            int cost  = mp[{left, i}] * mp[{i+1, right}];
            int leftSide = recursionMemo(arr, mp, left, i, dp);
            int rightSide = recursionMemo(arr, mp, i+1, right, dp);
            cost = cost + leftSide + rightSide;
            ans = min(ans, cost);
        }
        //2. update the dp
        dp[left][right] = ans;
        return ans;

    }

    int mctFromLeafValues(vector<int>& arr) {
        //precompuatation to find the max of all possible range
        int n = arr.size();
        map<pair<int, int>, int> mp;
        for(int i=0; i<n; i++)
        {   mp[{i, i}] = arr[i];
            for(int j=i+1; j<n; j++){
                mp[{i, j}] = max(arr[j], mp[{i, j-1}]); 
            }
        }

        int left = 0, right = n-1;
        //1. create dp
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return recursionMemo(arr, mp, left, right, dp);
    }
};