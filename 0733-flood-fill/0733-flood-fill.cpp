//we will solve it using DFS
//we do not require 2 loops as we will not require to check for each node
//so we can directly start with dfs fun with srr and src
//we will create a new vector<vector<int>> ans|
//ans = image
//we will also use visited map<pair<int, int>, bool> (coordinates, T/F)
//inside the dfs fun, 1st mark that coordinates as visited and update the ans with colour
//we will use 2 vectors (up, down, left, right)and use isSafe fun to process its nbrs
//if safe then call dfs
//finally return ans
class Solution {
public:
    // Helper to check boundaries
    bool isSafe(int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    void dfs(int x, int y, int newColor, int initialColor, vector<vector<int>>& image, vector<vector<int>>& ans, map<pair<int, int>, bool>& visited) {    
        // 1. Mark as visited
        visited[{x, y}] = true;
        // 2. Update the color in the answer vector
        ans[x][y] = newColor;
        int row = image.size();
        int col = image[0].size();
        // 3. Define directions (Up, Down, Left, Right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        // 4. Traverse neighbors
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            // 5. Check Safety
            if(isSafe(newX, newY, row, col)) {
                // CRITICAL CHECK:
                // We only proceed if it's NOT visited AND 
                // the neighbor has the SAME color as the starting pixel.
                if(!visited[{newX, newY}] && image[newX][newY] == initialColor) {
                    dfs(newX, newY, newColor, initialColor, image, ans, visited);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Capture the starting color (e.g., '1') so we know what to fill
        int initialColor = image[sr][sc];
        // Create the copy as requested
        vector<vector<int>> ans = image;
        // Create the map as requested
        map<pair<int, int>, bool> visited;
        // Start DFS directly (no loop needed)
        dfs(sr, sc, color, initialColor, image, ans, visited);
        return ans;
    }
};