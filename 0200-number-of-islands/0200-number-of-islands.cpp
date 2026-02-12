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
    bool isSafe(int newX, int newY, int row, int col) {
        return (newX >= 0 && newX < row && newY >= 0 && newY < col);
    }

    void bfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int row, int col, int startX, int startY) {
        queue<pair<int, int>> q;
        q.push({startX, startY});
        visited[startX][startY] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int cx = curr.first;
            int cy = curr.second;

            for (int i = 0; i < 4; i++) {
                int newX = cx + dx[i];
                int newY = cy + dy[i];

                if (isSafe(newX, newY, row, col)) {
                    if (!visited[newX][newY] && grid[newX][newY] == '1') {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int countAns = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    countAns++;
                    bfs(visited, grid, rows, cols, i, j);
                }
            }
        }
        return countAns;
    }
};