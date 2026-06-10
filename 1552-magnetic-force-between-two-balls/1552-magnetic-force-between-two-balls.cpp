class Solution {
public:
    bool isPossible(vector<int>& position, int n, int m, int minValue){
        //we need 2 variables
        int currBalls = 1;
        int prevPosition = position[0];
        //traverse through the bucket and see if u can fit them
        for(int i=1; i<n; i++){
            if(position[i] - prevPosition >= minValue){
                //trying to maximise the minimum
                currBalls++;
                prevPosition = position[i];
                //since we have updated the currBalls, 
                //check if we were bale to fit all
                if(currBalls==m){
                    return true;
                }
            }
            //no else condition in here
        }
        //we were not able to fit the balls in the buckets
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(); //buckets
        //similar to aggressive cows
        //maximise the minimum
        //binary search (logN)
        //BC, more balls than buckets
        if(m>n){
            return -1;
        }
        //1st sort it for we r going to use BS
        sort(position.begin(), position.end());
        //the best case and the worst case
        int low = 1;
        int high = position[n-1] - position[0];
        int ans = -1;
        //start the process now
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(position, n, m, mid)){
                //if its poissible then save the ans we need to maximise the minimum
                //so move the low
                ans = mid;
                low = mid + 1;
            }
            else{
                //this space was not enough so we have to move high
                high = mid -1;
            }
        } 
        return ans;
    }
};