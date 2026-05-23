class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //this is similar to merge intervals qs
        //this is done in N
        //we have to take advantage of the the sorting order and no-overlapping
        //so any intervals whos startingIndex is < the starting index of newInterval
        //can safely be pushed in 
        int i=0;
        int n = intervals.size();
        vector<vector<int>> ans;
        while(i<n && intervals[i][1] < newInterval[0]){
            //safely inserted
            ans.push_back(intervals[i]);
            i++;
        }
        //now we have to merge
        while(i<n &&  intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        //simply push it now
        ans.push_back(newInterval);
        //simply push the rest now
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};