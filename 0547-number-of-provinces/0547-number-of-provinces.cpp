class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int countAns = 0;
        vector<bool> isVisited(n, false);
        
        for (int i = 0; i < n; i++) {
            // If the node hasn't been visited, it's a new component
            if (!isVisited[i]) {
                countAns++;
                
                // Initialize BFS for this component
                queue<int> q;
                q.push(i);
                isVisited[i] = true;
                
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    // Explore neighbors directly through the matrix
                    for (int j = 0; j < n; j++) {
                        if (isConnected[curr][j] == 1 && !isVisited[j]) {
                            isVisited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        
        return countAns;
    }
};