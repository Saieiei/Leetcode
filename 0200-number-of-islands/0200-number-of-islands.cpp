//bfs
//traverse through each node
//traverse its nbrs in 4 directions
//check if the new coordinates r safe
//push back in q
//outside the while loop, increase ans
class Solution {
public:
    int isSafe(int newX, int newY, const int& m, const int& n, const vector<vector<char>>& grid, const vector<vector<bool>>& isVisited){
        if((newX<0 || newX>=m)||(newY<0 || newY>=n)||
        (grid[newX][newY] == '0') || (isVisited[newX][newY])){
            return false;
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //we need visited
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        //create q
        using p = pair<int, int>;
        queue<p> q;
        //explore nbrs, up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int countAns = 0;

        //traverse through the given matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check if node is land and not visited
                if(grid[i][j] == '1' && !isVisited[i][j]){
                    //push in the pq
                    q.push({i, j});
                    //as soon as u push, mark it visited
                    isVisited[i][j] = true;

                    while(!q.empty()){
                        pair<int, int> topPair = q.front();
                        q.pop();
                        int x = topPair.first;
                        int y = topPair.second;
                        //explore nbrs in all 4 directions
                        for(int k=0; k<4; k++){
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            //check if these new coordinates r safe
                            if(isSafe(newX, newY, m, n, grid, isVisited)){
                                //push that in q
                                q.push({newX, newY});
                                //as soon as u push, mark it visited
                                isVisited[newX][newY] = true;

                            }
                        }
                    }
                    //increase count
                    countAns++;
                }
            }
        }
        return countAns;
    }
};