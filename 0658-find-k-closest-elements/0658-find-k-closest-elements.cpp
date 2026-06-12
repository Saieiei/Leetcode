class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        //binnary search X 2 pointsers ✅ O(n-k)
        int low = 0;
        int high = n-1;
        //we hve to maintain the size of k elements
        //and it should be greater
        while(high - low >= k){
            //if they have teh same dist then clearly low wins
            //because there is no =
            if(x-arr[low]>arr[high]-x){
                //move the low closer to the x
                low++;
            }
            else{
                high--;
            }
        }
        //add 1 to the end because the ;last element in not taken
        //into consoderation when using exclusive iterator bounds
        vector<int>ans(arr.begin()+low, arr.begin()+high+1);
        return ans;
    }
};