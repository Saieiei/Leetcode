//M2 Memoization
//the dp is a little diff and we pass isSwap in recursion too now
//This is sim to include exclude principle
//we will have to return the min of it so inni to INT_MAX
//we will use pointers to track the previos 1 (P1, P2)
    //thes rest of the time we will pass p1 and p2 directly 
//swpa if th ecodition works
class Solution {
public:
    int recursionMemo(vector<int>& nums1, vector<int>& nums2, int indx, int p1, int p2, vector<vector<int>>&dp, int isSwap){
        //bc
        if(indx >= nums1.size()) return 0;
        if(dp[indx][isSwap] != -1) return dp[indx][isSwap];
        int swap = INT_MAX, NoSwap = INT_MAX;
        
        if(p1 < nums2[indx] && p2 < nums1[indx]){ //here swap p1 and p2
            swap =  1 + recursionMemo(nums1, nums2, indx + 1, nums2[indx], nums1[indx], dp, 1);
        }
        if(p1 < nums1[indx] && p2 < nums2[indx]){ //dont swap p1 and p2, but should be inc
            NoSwap = 0 + recursionMemo(nums1, nums2, indx + 1, nums1[indx], nums2[indx], dp, 0);
        }
        dp[indx][isSwap] =  min(swap, NoSwap);
        return dp[indx][isSwap];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int indx = 0, p1 = -1, p2 = -1, isSwap = 0; // here p1  and p2 r not index
        //we pass -1 just beasue of the 1st if condition
        vector<vector<int>>dp(nums1.size() + 1, vector<int>(2, -1)); //indx, swap/NoSwap
        return recursionMemo(nums1, nums2, indx, p1, p2, dp, isSwap);
    }
};