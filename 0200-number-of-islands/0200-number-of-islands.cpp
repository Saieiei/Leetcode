//dfs
class Solution {
public:
    bool isSafe(int i, int j, int m, int n){
        if((i<0 || i>=m) || (j<0 || j>=n)){
            return false;
        }
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        //if its safe
        if(isSafe(i, j, m, n)){
            //check if not visited
            if(grid[i][j] == '1'){
                //mark it as visited
                grid[i][j] = '0';
                //explore the nbrs, up, down, left, right
                dfs(i-1, j, grid);
                dfs(i+1, j, grid);
                dfs(i, j-1, grid);
                dfs(i, j+1, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //we dont need isVisited as i am going to mark it implace
        
        //traverse through the grid
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};