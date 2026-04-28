//dfs
class Solution {
public:
    void dfs(int x, int y, const int m, const int n, vector<vector<int>>& heights, vector<vector<bool>>& isVisitedOcean, int parentHeight){
        //1st check if the coordinates r not safe
        if((x<0 || x>=m)||(y<0 || y>=n)){
            return;
        }
        //check if already visited
        if(isVisitedOcean[x][y] == true){
            return;
        }
        //check if water cannot flow
        if(parentHeight > heights[x][y]){
            return;
        }
        
        //its safe now, mark it as visited
        isVisitedOcean[x][y] = true;
        
        //explore its nbrs
        //up, down, left, right
        dfs(x-1, y, m, n, heights, isVisitedOcean, heights[x][y]);
        dfs(x+1, y, m, n, heights, isVisitedOcean, heights[x][y]);
        dfs(x, y-1, m, n, heights, isVisitedOcean, heights[x][y]);
        dfs(x, y+1, m, n, heights, isVisitedOcean, heights[x][y]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int totalNodes = m*n;
        vector<vector<bool>> isVisitedPacific(m, vector<bool>(n, false));
        vector<vector<bool>> isVisitedAtlantic(m, vector<bool>(n, false));
        vector<vector<int>> ans;

        //dont have to visit through the matrix
        //we have our 4 ways to traverse through
        //pacific
        for(int i=0; i<n; i++){
            int y = i;
            int x = 0;
            int parentHeight = -1;
            if(isVisitedPacific[x][y] == false){
                dfs(x, y, m, n, heights, isVisitedPacific, parentHeight);
            }
        }
        for(int i=0; i<m; i++){
            int x = i;
            int y = 0;
            int parentHeight = -1;
            if(isVisitedPacific[x][y] == false){
                dfs(x, y, m, n, heights, isVisitedPacific, parentHeight);
            }
        }
        //atlantic
        for(int i=0; i<n; i++){
            int y = i;
            int x = m-1;
            int parentHeight = -1;
            if(isVisitedAtlantic[x][y] == false){
                dfs(x, y, m, n, heights, isVisitedAtlantic, parentHeight);
            }
        }
        for(int i=0; i<m; i++){
            int x = i;
            int y = n-1;
            int parentHeight = -1;
            if(isVisitedAtlantic[x][y] == false){
                dfs(x, y, m, n, heights, isVisitedAtlantic, parentHeight);
            }
        }

        //compute ans
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isVisitedPacific[i][j] == true && isVisitedAtlantic[i][j] == true){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};