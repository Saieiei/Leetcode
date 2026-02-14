//Tarjans Algo
class Solution {
private:
    int timer = 1;
    
    void dfs(int src, int parent, vector<int>& vis, vector<vector<int>>& adj, 
             vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        
        vis[src] = 1;
        tin[src] = low[src] = timer;
        timer++;
        
        for (auto nbr : adj[src]) {
            if (nbr == parent) continue;
            
            if (vis[nbr] == 0) {
                // If unvisited, perform DFS
                dfs(nbr, src, vis, adj, tin, low, bridges);
                
                // On backtracking, update low time of the current node
                low[src] = min(low[src], low[nbr]);
                
                // Check bridge condition
                if (low[nbr] > tin[src]) {
                    bridges.push_back({src, nbr});
                }
            } else {
                // Back-edge found, update low time
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 1. Create the adjacency list from the given connections
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        // 2. Initialize tracking arrays
        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        
        // 3. The problem states it's a connected graph, 
        // so a single DFS starting from node 0 is sufficient
        int src = 0, parent = -1;
        dfs(src, parent, vis, adj, tin, low, bridges);
        
        return bridges;
    }
};