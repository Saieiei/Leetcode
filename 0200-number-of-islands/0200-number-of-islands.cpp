//DFS
//https://leetcode.com/problems/number-of-provinces/description/
class Solution {
public:
    // This recursive function replaces the BFS loop + Queue
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int rows, int cols) {
        // 1. BASE CASE: Boundary Checks (If out of bounds, stop)
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        // 2. BASE CASE: If water ('0') or already visited, stop
        if (grid[r][c] == '0' || visited[r][c]) {
            return;
        }

        // 3. Mark as visited
        visited[r][c] = true;

        // 4. Recursive Step: Visit all 4 neighbors
        // We don't need a loop here; explicit calls are often faster/clearer in DFS
        dfs(grid, visited, r + 1, c, rows, cols); // Down
        dfs(grid, visited, r - 1, c, rows, cols); // Up
        dfs(grid, visited, r, c + 1, rows, cols); // Right
        dfs(grid, visited, r, c - 1, rows, cols); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        
        int countAns = 0;
        
        // Keep the visited array (O(M*N) space)
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If we find unvisited land
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // Start the recursion to sink the whole island
                    dfs(grid, visited, i, j, rows, cols);
                    countAns++;
                }
            }
        }
        return countAns;
    }
};