//M2 Memoization
//we cannot offord to make 1e9 vector dp, so we use map
//related to include exclude principle
//1st sort arr2
//if p1 < arr1[i] then u have 2 options, p1 is more like a value than indx
    //include it with the help of upperbound of prev on arr2 (using it)
        //and swap the bigger (arr1[i]) 1 with upperbound
    //exclude it and just move forward
//return min of both
//INT_MAX is more than double your defined INF, Because 1 + INT_MAX overflows (bad),
#define INF (1e9 + 1) 
class Solution {
public:
    int recursion(vector<int>& arr1, vector<int>& arr2, int p1, int indx, map<pair<int, int>, int>&dp){
        //bc
        if(indx >= arr1.size()) return 0;
        if(dp.find({p1, indx}) != dp.end()) return dp[{p1, indx}];

        int swap = INF, NoSwap = INF;
        if(p1 < arr1[indx]) //this time we exclude
            NoSwap = 0 + recursion(arr1, arr2, arr1[indx], indx + 1, dp);
        //swaping irrespective of the condition
        auto it = upper_bound(arr2.begin(), arr2.end(), p1); //prev
        if(it != arr2.end()){
            int indexToSwap = it - arr2.begin();
            //we should not modify the actual array
            //arr1[indx] = arr2[indexToSwap]; //so pass it directly in recursion
            swap = 1 + recursion(arr1, arr2, arr2[indexToSwap], indx + 1, dp);
        }
        
        return dp[{p1, indx}] = min(swap, NoSwap);

    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        int p1 = -1, indx = 0;
        map<pair<int, int>, int> dp; //p1, indx -> ans
        int ans = recursion(arr1, arr2, p1, indx, dp);
        return (ans == INF ? -1 : ans);
    }
};