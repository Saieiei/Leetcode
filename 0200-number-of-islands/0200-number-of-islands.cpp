//DFS, space optimised -> visited => grid
class Solution {
public:
    void dfsIterative(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // HERE IS THE STACK! (Explicitly defined)
        stack<pair<int, int>> s;
        s.push({r, c});
        
        // While stack is not empty (similar to BFS queue loop)
        while (!s.empty()) {
            pair<int, int> curr = s.top();
            s.pop();
            
            int row = curr.first;
            int col = curr.second;
            
            // Check bounds and if processed
            if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0') {
                continue;
            }
            
            // Mark visited (Sink the island)
            grid[row][col] = '0';
            
            // Push neighbors to stack
            s.push({row + 1, col}); // Down
            s.push({row - 1, col}); // Up
            s.push({row, col + 1}); // Right
            s.push({row, col - 1}); // Left
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfsIterative(grid, i, j);
                }
            }
        }
        return count;
    }
};