//https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
//here we used dijkdtras algo but only do right and down
class Solution
{
    public:
    // Helper to check if a coordinate is inside the grid
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    // Function to return the minimum cost to reach the bottom right cell
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int totalNodes = n * m;

        // --- STEP 1: PRE-PROCESSING (Build the Graph) ---
        // adj[u] stores pairs of {weight, v}
        vector<vector<pair<int, int>>> adj(totalNodes);

        // Directions for building the graph: ONLY Right and Down
        int dx[] = {0, 1}; 
        int dy[] = {1, 0}; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                // Current Node ID
                int u = i * m + j;

                // Check ONLY the 2 allowed neighbors (Right, Down)
                for(int k = 0; k < 2; k++) { 
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(isValid(ni, nj, n, m)) {
                        int v = ni * m + nj; // Neighbor Node ID
                        int weight = grid[ni][nj]; // Cost is value of destination cell
                        
                        // Add edge u -> v with weight
                        adj[u].push_back({weight, v});
                    }
                }
            }
        }

        // --- STEP 2: DIJKSTRA (Standard Graph Logic) ---
        // Min-heap: {accumulated_cost, node_id}
        set<pair<int, int>> st;
        
        // Dist array: now 1D because we mapped 2D -> 1D
        vector<int> dist(totalNodes, INT_MAX);

        // Initialization
        int startNode = 0;
        int targetNode = totalNodes - 1;
        
        dist[startNode] = grid[0][0];
        st.insert({grid[0][0], startNode});

        while(!st.empty()) {
            // Get top element
            auto it = st.begin();
            int currentCost = it->first;
            int u = it->second;
            st.erase(it);

            // Optimization: Stop if we reached target
            if (u == targetNode) return currentCost;

            // Iterate over neighbors using the pre-built AdjList
            for(auto edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                // Relaxation
                if(dist[u] + weight < dist[v]) {
                    // Remove old pair if it exists
                    if(dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    
                    dist[v] = dist[u] + weight;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist[targetNode];
    }
};