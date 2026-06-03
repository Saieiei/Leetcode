class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        //brute force N
        //space optimised O(1)
        int max = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > max){
                ans = i;
                max = arr[i];
            }
        }
        return ans;
    }
};