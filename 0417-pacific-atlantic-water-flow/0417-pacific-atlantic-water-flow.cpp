//we will solve this q in other way
//we will figure out which cells from the ocean can go deep into the map
//so we will have to check if the cell height <= nbr cell to affect it
//we will keep 2 visited vectors for each ocean
//then take the intersection of them and return that ans
class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& oceanVisted, int x, int y, int totalRows, int totalCols){
        //mark it as visited
        oceanVisted[x][y] = true;
        //affect its nbrs
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(int i=0; i<4; i++){
            int newX = dx[i] + x;
            int newY = dy[i] + y;
            if(newX>=0 && newX<totalRows && newY>=0 && newY<totalCols 
                && !oceanVisted[newX][newY] && heights[x][y] <= heights[newX][newY]){
                dfs(heights, oceanVisted, newX, newY, totalRows, totalCols);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int totalRows = heights.size();
        int totalCols = heights[0].size();
        int totalCells = totalRows * totalCols;
        vector<vector<bool>> pacificVisited(totalRows, vector<bool>(totalCols, false));
        vector<vector<bool>> atlanticVisited(totalRows, vector<bool>(totalCols, false));
        //prcoess the pacificVisited
        for(int col = 0; col < totalCols; col++){
            dfs(heights, pacificVisited, 0, col, totalRows, totalCols);
        }
        for(int row = 0; row < totalRows; row++){
            dfs(heights, pacificVisited, row, 0, totalRows, totalCols);
        }
        //process the atlanticVisited
        for(int col = 0; col < totalCols; col++){
            dfs(heights, atlanticVisited, totalRows-1, col, totalRows, totalCols);
        }
        for(int row = 0; row < totalRows; row++){
            dfs(heights, atlanticVisited, row, totalCols -1, totalRows, totalCols);
        }
        //find the intersection
        vector<vector<int>> ans;
        for(int i=0; i<totalRows; i++){
            for(int j=0; j<totalCols; j++){
                if(pacificVisited[i][j] == true && atlanticVisited[i][j] == true){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};