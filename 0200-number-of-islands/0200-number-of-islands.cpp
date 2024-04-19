class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        // 1st we will go through each cells
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++; // number of islands
                    rec(grid, i, j); // this will convert the visited cells (land='1') to '2'
                }
            }
        }
        return ans;
    }
    
    void rec(vector<vector<char>>& grid, int i, int j) {
        // checking some default cases
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c)
            return;
        if (grid[i][j] == '0' || grid[i][j] == '2')
            return;
        if (grid[i][j] == '1') {
            grid[i][j] = '2';
            rec(grid, i, j + 1);
            rec(grid, i, j - 1);
            rec(grid, i - 1, j);
            rec(grid, i + 1, j);
        }
    }
};
