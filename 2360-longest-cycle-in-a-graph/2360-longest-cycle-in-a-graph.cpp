//BFS - cyclke detection
//Traverse the remaining unvisited nodes (which form the cycles)
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        
        // 1. Calculate in-degrees for all nodes
        for (int i = 0; i < n; ++i) {
            int nbrNode = edges[i];
            if (nbrNode != -1) { //imp
                indegree[nbrNode]++;
            }
        }
        
        // 2. Queue all nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // 3. Kahn's Algorithm to peel away non-cycle nodes
        vector<bool> visited(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true; // Mark non-cycle nodes as visited
            
            int nbrNode = edges[node];
            if (nbrNode != -1) {
                indegree[nbrNode]--;
                if (indegree[nbrNode] == 0) {
                    q.push(nbrNode);
                }
            }
        }
        
        // 4. Traverse the remaining unvisited nodes (which form the cycles)
        int maxLength = -1;
        for (int i = 0; i < n; ++i) {
            int node = i;
            if (!visited[node]) {
                int length = 0;
                
                // Count the nodes in this specific cycle
                while (!visited[node]) {
                    visited[node] = true;
                    node = edges[node]; //node becomes the nbr
                    length++;
                }
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};