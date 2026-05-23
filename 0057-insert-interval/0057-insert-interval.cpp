class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //this is similar to merge intervals qs
        //we will use BS cuz its sorted
        //X NlogN its just N
        //we will insert newInterval in the interval based on BS
        int n = intervals.size();
        int low = 0;
        int high = n-1;
        //initially we have decided to insert the newInterval in the last index
        int toInsert = n;
        //BS start the process
        while(low<=high){
            int mid = low + (high - low)/2;
            if(intervals[mid][0] >= newInterval[0]){
                //we have found a possible case
                toInsert = mid;
                high = mid -1;
            }
            //bring the low to mid
            else{
                low = mid + 1;
            }
        }
        //so now we know where to insert it
        intervals.insert(intervals.begin() + toInsert, newInterval);
        //the rest of the process is same as the merge interval
        vector<vector<int>>ans;
        //push the initial 1
        ans.push_back(intervals[0]);
        //process the rest
        n = intervals.size();
        for(int i=1; i<n; i++){
            //check if ist overlapping
            if(ans.back()[1] >= intervals[i][0]){
                //we have to merge now
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                //simply push
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};