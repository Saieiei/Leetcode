class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //this is similar to merge intervals qs
        //naive method - insert newInterval in intervals
        //NlogN instead of N
        intervals.push_back(newInterval);
        //continue with the rest of the merge interval process
        //it was already sorted, but then since we pushed, 
        //we have to sort it again
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        //push the 1st row as it is in the ans
        ans.push_back(intervals[0]);
        int n = intervals.size();
        //star the loop till n
        for(int i=1; i<n; i++){
            //check if they r overlapping
            if(ans.back()[1] >= intervals[i][0]){
                //if so merge them
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