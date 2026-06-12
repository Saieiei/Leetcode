class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        //proper Binary Search O(N-K)
        //the left boundry of our k-sized window
        // should be atmost size-k
        int low = 0;
        int high = n-k;
        while(low<high){
            int mid = low + (high - low)/2;
            if(x-arr[mid]>arr[mid + k]-x){
                //move low closer to mid
                low = mid + 1;
            }
            else{
                //move high closer to mid but not -1
                high = mid;
            }
        }
        //get the ans
        vector<int>ans(arr.begin()+low, arr.begin()+low+k);
        return ans;
    }
};