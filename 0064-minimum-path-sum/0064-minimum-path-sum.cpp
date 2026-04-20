//inplace optimization
//no dijkstra
//this is like sweaping from topleft to bottom right
//covering a triangular area and moving towards bottom right
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        //we have to process each node
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                //if starting node then ignore
                if(i == 0 && j == 0){
                    continue;
                }
                if(i==0){
                    grid[i][j] = grid[i][j] + grid[i][j-1];
                }
                else if(j==0){
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                }
                else{
                    grid[i][j] = min(grid[i][j] + grid[i][j-1], grid[i][j] + grid[i-1][j]);
                }
            }
        }
        return grid[rows - 1][cols -1];
    }
};