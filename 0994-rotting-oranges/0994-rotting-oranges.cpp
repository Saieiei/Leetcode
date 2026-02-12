//dfs space optimised
class Solution {
public:
    // Helper function to check if a cell is valid and needs processing
    // It is "Safe" if it is within bounds AND it is a FRESH orange ('1')
    bool isSafe(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Structure to store {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        
        // REMOVED: vector<vector<int>> temp = grid;
        // We will now use 'grid' directly for everything.
        
        // 1. Traverse grid to find all initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    // Push all starting rotten oranges with time = 0
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int finalTimeAns = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // 2. Start BFS
        while(!q.empty()) {
            pair<int, int> currPos = q.front().first;
            int currTime = q.front().second;
            q.pop();
            
            int r = currPos.first;
            int c = currPos.second;
            
            // Process 4 neighbors
            for(int i = 0; i < 4; i++) {
                int newR = r + dx[i];
                int newC = c + dy[i];
                
                // Check if neighbor is valid and is a FRESH orange (1)
                // Pass 'grid' instead of 'temp'
                if(isSafe(newR, newC, n, m, grid)) {
                    // Mark as rotten (visited) immediately in the ORIGINAL grid
                    grid[newR][newC] = 2;
                    
                    // Push to queue with time + 1
                    q.push({{newR, newC}, currTime + 1});

                    // Update the max time we have reached
                    finalTimeAns = max(finalTimeAns, currTime + 1);
                }
            }
        }
        
        // 3. Final check: Are there any fresh oranges left in the ORIGINAL grid?
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1; // Impossible to rot all oranges
                }
            }
        }
        
        return finalTimeAns;
    }
};