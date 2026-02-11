//We will be solving this with the help of BFS
//for BFS we need visited[] and queue
//we have to process its neighbors but we DON’T NEED adjList
//we will have to process each node so we require 2 loops
//as soon as it comes out from BFS (present inside the 2 loop) -> count++
//u come out from BFS fun when the queue is empty
//u will only vist the nodes if its marked false and marked ‘1’
//inside BFS u will have to mark it visited and remove it from queue and process its neighbors
//for processing its neighbors u require 2 arrays to move up down left right and pass them in safe fun
//once safe u have to check if they r not visited and marked ‘1’
//safe fun checks if the neighbors bounds r within the graph (vector<vector<int>>)
//if so push them in queue and mark them as visited.
//in the end outside the 2 loops return count
class Solution {
public:
    bool isSafe(int& newX, int& newY, int& row, int& col){
        if(newX>=0 && newX<row && newY>=0 && newY<col){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(map<pair<int, int>, bool>& visited, vector<vector<char>>& grid, queue<pair<int, int>>& q, int& row, int& col){
        while(!q.empty()){
            pair<int, int> firstNodeIndexs = q.front();
            q.pop();
            int nodeX = firstNodeIndexs.first;
            int nodeY = firstNodeIndexs.second;
            vector<int> dx{-1, 1, 0, 0};
            vector<int> dy{0, 0, -1, 1};
            for(int i=0; i<4; i++){
                int newX = dx[i] + nodeX;
                int newY = dy[i] + nodeY;
                if(isSafe(newX, newY, row, col)){
                    if(!visited[{newX, newY}] && grid[newX][newY] == '1'){
                        q.push({newX, newY});
                        visited[{newX, newY}] = true;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int, int>, bool>visited; //location, visited or not
        queue<pair<int, int>>q;
        int countAns = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[{i, j}] && grid[i][j] == '1'){
                    q.push({i, j});
                    visited[{i, j}] = true;
                    bfs(visited, grid, q, row, col);
                    countAns++;
                }
            }
        }
        return countAns;
    }
};