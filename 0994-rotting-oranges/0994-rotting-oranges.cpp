//We will use BFS to solve this problem
//we will have to traverse through each of the node 1st (2 loops)
//This is because we have to insert all the rotten ones in the queue
//queue<pair<pair<int, int>, int>q //coordinates, time
//vector<vector<int>> temp = grid
//then we start bfs fun
//the bfs fun will keep running until the q is empty
//inside the bfs fun, we will start processing its nbrs
//dx[], dy[], forloop(i<4)
//for each nbr check it with isSafe fun
//isSafe fun checks if the coordinates r valid and its not rotten
//if safe, push it in the q by incrementing the time by 1 and mark it as 2 in the temp 
//and finalTimeAns= max(finalTimeAns, incremented time by 1)
//after bfs fun returns start to traverse through each node in the temp (2 for loops)
//if in any u get 1 the return -1 (not possible to infect all)
//else return finalTimeAns;
class Solution {
public:
    // 1. Helper: Check if coordinates are valid and it's a fresh orange
    bool isSafe(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            return true;
        }
        return false;
    }
    // 2. BFS Function: Processes the queue and updates the grid & time
    void bfs(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& grid, int& finalTimeAns, int n, int m) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()) {
            pair<int, int> currPos = q.front().first;
            int currTime = q.front().second;
            q.pop();
            int r = currPos.first;
            int c = currPos.second;
            // Process neighbors
            for(int i = 0; i < 4; i++) {
                int newR = r + dx[i];
                int newC = c + dy[i];
                // Check if neighbor is valid and is a FRESH orange
                if(isSafe(newR, newC, n, m, grid)) {
                    // Mark as rotten (visited) immediately
                    grid[newR][newC] = 2;
                    // Push to queue with time + 1
                    q.push({{newR, newC}, currTime + 1});
                    // TRACK MAX TIME HERE (Inside isSafe)
                    // We use 'currTime + 1' because this is the time the NEIGHBOR rots
                    finalTimeAns = max(finalTimeAns, currTime + 1);
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();    
        queue<pair<pair<int, int>, int>> q;
        // 1. Find all initially rotten oranges and push to queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        int finalTimeAns = 0;
        // 2. Call the BFS function
        bfs(q, grid, finalTimeAns, n, m);
        // 3. Final Check: Did we miss any fresh oranges?
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1; 
                }
            }
        }
        return finalTimeAns;
    }
};