class Solution {
public:
    bool isSafe(int newX, int newY, int m, int n) {
        if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
            return false;
        }
        return true;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // helper, down, right
        int dx[] = {1, 0};
        int dy[] = {0, 1};

        // dijkstra algo directly on grid
        // set stores {weight, {x_coordinate, y_coordinate}}
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        
        st.insert({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        // start the process
        while (!st.empty()) {
            auto topPair = *st.begin();
            st.erase(st.begin());
            
            int nodeWt = topPair.first;
            int x = topPair.second.first;
            int y = topPair.second.second;

            // Skip if already processed
            if (isVisited[x][y]) {
                continue;
            }
            isVisited[x][y] = true;

            // explore the nbrs
            for (int k = 0; k < 2; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (isSafe(newX, newY, m, n) && !isVisited[newX][newY]) {
                    int nbrWt = grid[newX][newY];
                    
                    if (nodeWt + nbrWt < dist[newX][newY]) {
                        // update the dist and push in st
                        // before that, if found in st, erase it
                        if (dist[newX][newY] != INT_MAX) {
                            st.erase({dist[newX][newY], {newX, newY}});
                        }
                        
                        dist[newX][newY] = nodeWt + nbrWt;
                        st.insert({dist[newX][newY], {newX, newY}});
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1];
    }
};