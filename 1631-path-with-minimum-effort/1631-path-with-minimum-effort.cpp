class Solution {
public:
    // Helper to check if a coordinate is inside the grid
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int totalNodes = n * m;

        // --- STEP 1: PRE-PROCESSING (Build the Graph) ---
        // adj[u] stores pairs of {weight, v}
        // Weight here = Absolute difference in heights between the two cells
        vector<vector<pair<int, int>>> adj(totalNodes);

        // Directions (Up, Down, Left, Right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                int u = i * m + j; // Current Node ID

                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(isValid(ni, nj, n, m)) {
                        int v = ni * m + nj; // Neighbor Node ID
                        
                        // EDGE WEIGHT = Absolute difference in heights
                        int weight = abs(heights[i][j] - heights[ni][nj]);
                        
                        adj[u].push_back({weight, v});
                    }
                }
            }
        }

        // --- STEP 2: DIJKSTRA (Modified for "Effort") ---
        
        // Min-heap: {current_max_effort, node_id}
        set<pair<int, int>> st;
        
        // Dist array: Stores the MINIMUM EFFORT required to reach each node
        vector<int> dist(totalNodes, INT_MAX);

        int startNode = 0;
        int targetNode = totalNodes - 1;
        
        // Initial effort is 0 (standing at start requires no effort)
        dist[startNode] = 0;
        st.insert({0, startNode});

        while(!st.empty()) {
            auto it = st.begin();
            int currentEffort = it->first;
            int u = it->second;
            st.erase(it);

            // Optimization: Stop if we reached target
            if (u == targetNode) return currentEffort;

            // Iterate neighbors
            for(auto edge : adj[u]) {
                int edgeWeight = edge.first; // The jump height to this neighbor
                int v = edge.second;

                // --- THE CRITICAL LOGIC CHANGE ---
                // The effort to get to 'v' is the MAX of:
                // 1. The effort it took to get to 'u'
                // 2. The jump from 'u' to 'v'
                int newEffort = max(currentEffort, edgeWeight);

                // Relaxation: If we found a route with a smaller "max jump", update it
                if(newEffort < dist[v]) {
                    if(dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    
                    dist[v] = newEffort;
                    st.insert({dist[v], v});
                }
            }
        }
        
        return dist[targetNode]; // Should always find a path
    }
};