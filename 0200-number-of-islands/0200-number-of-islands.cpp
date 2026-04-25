//dfs
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& isVisited, vector<vector<char>>& grid){
        //1st check if that coordiniates r safe
        int m = grid.size();
        int n = grid[0].size();
        if((i<0 || i>=m)||(j<0 || j>=n)||(grid[i][j] == '0')){
            //not safe
            return;
        }

        //check if already visited
        if(isVisited[i][j]){
            return;
        }

        //all safe, mark it is visited
        isVisited[i][j] = true;

        //spread the infection
        //up, down, left , right
        dfs(i-1, j, isVisited, grid);
        dfs(i+1, j, isVisited, grid);
        dfs(i, j-1, isVisited, grid);
        dfs(i, j+1, isVisited, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //for dfs we need isVisited
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));

        int countAns = 0;
        //start dfs
        //traverse through each node
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){ 
                //if land and not visited
                if(grid[i][j] == '1' && !isVisited[i][j]){
                    dfs(i, j, isVisited, grid);
                    countAns++;
                }
            }
        }
        return countAns;
    }
};