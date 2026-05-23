class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //simple matrix traversal, pointers
        //make sure to sort it because it is not guaranteed to be sorted
        sort(intervals.begin(), intervals.end());

        //now start the process
        vector<vector<int>> ans;
        //simply push the 1st 1 for now
        //1st row
        vector<int> row1st = intervals[0];
        ans.push_back(row1st);

        //now analyse for th erest of the rows
        for(int i=1; i<n; i++){
            vector<int> nextRow = intervals[i];
            int startNextRowIndex = nextRow[0];
            int endNextRowIndex = nextRow[1];
            //check if out last index in latest row 
            //in ans is >= startNextRowIndex
            vector<int> currentRow = ans.back();
            int startCurrentRow = currentRow[0];
            int endCurrentRow = currentRow[1];
            if(endCurrentRow >= startNextRowIndex){
                //merge them
                ans.back()[1] = max(ans.back()[1], nextRow[1]);
            }
            else{
                //cant do anything, simply push the nextRow in the ans
                ans.push_back(nextRow);
            }
        }
        return ans;
    }
};