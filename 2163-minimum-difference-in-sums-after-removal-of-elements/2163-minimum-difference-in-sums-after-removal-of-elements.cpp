#define ll long long
//to solve this we will do prefix - suffix
//prefix is going to be with max heap to remove if its greater than N size
//same for suffix but for min heap
//now to find out the min of prefix[i] - suffix[i+1] we will do for loop from n-1 to 2*n 
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3; //idk y we do /3
        ll sum = 0;
        vector<ll>prefix(nums.size(), -1);
        vector<ll>suffix(nums.size(), -1);
        priority_queue<ll> pq1;
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        ll ans = LONG_LONG_MAX;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            pq1.push(nums[i]);
            if(pq1.size() > n){
                ll front = pq1.top(); pq1.pop();
                sum -= front;
            }
            if(pq1.size() == n){
                prefix[i] = sum;
            }
        }

        sum = 0;
        for(int i=nums.size()-1; i>=0; i--){
            sum += nums[i];
            pq2.push(nums[i]);
            if(pq2.size() > n){
                ll front = pq2.top(); pq2.pop();
                sum -= front;
            }
            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }

        for(int i=n-1; i<2*n; i++){
            ans = min(ans, prefix[i]-suffix[i+1]);
        }
        return ans;

    }
};