//dfs
class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>& minTime, int currentTime){
        //check if the coordinates r safe
        if((i<0 || i>=m)||(j<0 || j>=n)||(grid[i][j] == 0)){
            return;
        }
        // CRITICAL FIX: check if the coordinates r already visited efficiently
        // This must apply to ALL valid cells, not just 2s!
        if (currentTime >= minTime[i][j]) {
            return;
        }

        //We found a faster route to rot this orange! Update it.
        minTime[i][j] = currentTime;

        //spread the infection in 4 directions
        dfs(i-1, j, m, n, grid, minTime, currentTime+1);
        dfs(i+1, j, m, n, grid, minTime, currentTime+1);
        dfs(i, j-1, m, n, grid, minTime, currentTime+1);
        dfs(i, j+1, m, n, grid, minTime, currentTime+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxTimeAns = 0;
        //dfs is not guaranteed to give the min ans
        //so we have to keep track of time
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        int currentTime = 0;

        //traverse through the loop
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check if rotten orange
                if(grid[i][j] == 2){
                    dfs(i, j, m, n, grid, minTime, currentTime);
                }
            }
        }
        // Verify if all fresh oranges were infected and find the max time taken
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // If it's a fresh orange but its time is still 1e9, it was unreachable
                    if (minTime[i][j] == INT_MAX) {
                        return -1;
                    }
                    // Capture the maximum time it took to reach any orange
                    maxTimeAns = max(maxTimeAns, minTime[i][j]);
                }
            }
        }
        return maxTimeAns;

    }
};