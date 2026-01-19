//M3 Tabulation
//we will have to go from size-1 to 1 as will insert -1 for p1 and p2 in the vectors
//and also we will have to swap if isSwap
//the dp is a little diff and we pass isSwap in recursion too now
//This is sim to include exclude principle
//we will have to return the min of it so inni to INT_MAX
//we will use pointers to track the previos 1 (P1, P2)
    //thes rest of the time we will pass p1 and p2 directly 
//swpa if th ecodition works
class Solution {
public:
    int recursionTabu(vector<int>& nums1, vector<int>& nums2, int indx, int p1, int p2, int isSwap){
        //bc
        vector<vector<int>>dp(nums1.size() + 1, vector<int>(2, 0));
        if(indx >= nums1.size()) return 0;
        //if(dp[indx][isSwap] != -1) return dp[indx][isSwap];

        for(int I = nums1.size() - 1; I >= 1; I--){
            for(int j = 1; j >= 0; j--){
                if(j) swap(p1, p2); //idk y 
                p1 = nums1[I - 1]; p2 = nums2[I - 1];
                int swap = INT_MAX, NoSwap = INT_MAX;
                if(p1 < nums2[I] && p2 < nums1[I]){ //here swap p1 and p2
                    swap =  1 + dp[I + 1][1];
                }
                if(p1 < nums1[I] && p2 < nums2[I]){ //dont swap p1 and p2, but should be inc
                    NoSwap = 0 + dp[I + 1][0];
                }
                dp[I][isSwap] =  min(swap, NoSwap);
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int indx = 0, p1 = -1, p2 = -1, isSwap = 0; // here p1  and p2 r not index
        //we pass -1 just beasue of the 1st if condition
        nums1.insert(nums1.begin(), -1); nums2.insert(nums2.begin(), -1);
        return recursionTabu(nums1, nums2, indx, p1, p2, isSwap);
    }
};