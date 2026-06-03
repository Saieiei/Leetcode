class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        //brute force N
        priority_queue<pair<int, int>> pq; //num, index
        //populate pq
        for(int i=0; i<n; i++){
            pq.push({arr[i], i});
        }
        int ans = pq.top().second;
        return ans;
    }
};